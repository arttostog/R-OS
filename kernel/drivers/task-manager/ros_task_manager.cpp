#include <./drivers/task-manager/ros_task_manager.h>

using namespace ROS;

uint32_t TaskManager::tasksIndex = 0;

extern "C" {
    void (*tasks[CORES_FOR_TASKS]) () = {};

    void kernel_tasks(IN uint64_t coreId) {
        void (**task) () = &tasks[coreId - 1];
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