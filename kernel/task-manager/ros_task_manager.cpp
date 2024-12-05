#include <./task-manager/ros_task_manager.h>

extern "C" {
    void (*tasks[CORES_FOR_TASKS]) () = {};

    void kernel_tasks(uint64_t coreId) {
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