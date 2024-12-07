#ifndef ROS_TASK_MANAGER_H
#define ROS_TASK_MANAGER_H

#include <ros_standart.h>

#define CORES_FOR_TASKS 3

extern "C" {
    extern void (*tasks[CORES_FOR_TASKS]) ();
}

namespace ROS {
    class TaskManager {
    public:
        static void addTask(IN void (*task) ());
    private:
        static uint32_t tasksIndex;
        static void updateTasksIndex();
    };
}

#endif