#ifndef ROS_TASK_MANAGER_H
#define ROS_TASK_MANAGER_H

#include <ros_standart.h>

namespace ROS {
    class TaskManager {
    public:
        typedef void (*pptr)(); // Pointer to procedure ( void procedure(); )

        static constexpr uint32_t CORES_FOR_TASKS = 3;
        static bool coresState[CORES_FOR_TASKS];
        static void (*tasks[CORES_FOR_TASKS]) ();

        static pptr* addTask(IN pptr task);
        static void awaitAddedTask(IN pptr* addedTask);
    private:
        static uint32_t coreIndex;

        static void updateTasksIndex();
    };
}

#endif