#ifndef ROS_TASK_MANAGER_H
#define ROS_TASK_MANAGER_H

#include <ros_standart.h>

namespace ROS {
    class TaskManager {
    public:
        static const uint32_t CORES_FOR_TASKS = 3;
        static void (*tasks[CORES_FOR_TASKS]) ();

        static void addTask(IN void (*task) ());
    private:
        static uint32_t tasksIndex;

        static void updateTasksIndex();
    };
}

#endif