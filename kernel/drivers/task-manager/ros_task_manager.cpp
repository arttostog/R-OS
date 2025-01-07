#include <./drivers/task-manager/ros_task_manager.h>

using namespace ROS;

bool TaskManager::coresState[TaskManager::CORES_FOR_TASKS] = { };
void (*TaskManager::tasks[TaskManager::CORES_FOR_TASKS]) () = { };
uint32_t TaskManager::coreIndex = 0;

extern "C" {
    void kernel_tasks(IN uint64_t coreId) {
        TaskManager::coresState[coreId - 1] = true;
        void (**task) () = &TaskManager::tasks[coreId - 1];
        while (true)
        {
            if (*task != nullptr) {
                (*task)();
                *task = nullptr;
            }
        }
    }
}

void TaskManager::addTask(IN void (*task) ()) {
    while (true) {
        if (coresState[coreIndex] && tasks[coreIndex] == nullptr) {
            tasks[coreIndex] = task;
            updateTasksIndex();
            break;
        }
        updateTasksIndex();
    }
}

void TaskManager::updateTasksIndex() {
    if (++coreIndex == CORES_FOR_TASKS)
        coreIndex = 0;
}