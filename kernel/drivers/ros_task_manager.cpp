#include <./drivers/ros_task_manager.h>

using ROS::TaskManager;

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

TaskManager::pptr* TaskManager::addTask(IN TaskManager::pptr task) {
    while (true) {
        if (coresState[coreIndex] && tasks[coreIndex] == nullptr) {
            tasks[coreIndex] = task;
            return &tasks[coreIndex];
        }
        updateTasksIndex();
    }
}

void TaskManager::updateTasksIndex() {
    if (++coreIndex == CORES_FOR_TASKS)
        coreIndex = 0;
}

void TaskManager::awaitAddedTask(IN TaskManager::pptr* addedTask) {
    while (*addedTask != nullptr)
        continue;
}