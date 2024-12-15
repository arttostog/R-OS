#include <./system/task-manager/ros_task_manager.h>

using namespace ROS;

void (*TaskManager::tasks[TaskManager::CORES_FOR_TASKS]) () = { };
uint32_t TaskManager::tasksIndex = 0;

extern "C" {
    void kernel_tasks(IN uint64_t coreId) {
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
        if (tasks[tasksIndex] == nullptr) {
            tasks[tasksIndex] = task;
            updateTasksIndex();
            break;
        }
        updateTasksIndex();
    }
}

void TaskManager::updateTasksIndex() {
    if (++tasksIndex == CORES_FOR_TASKS)
        tasksIndex = 0;
}