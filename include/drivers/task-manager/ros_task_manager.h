#ifndef ROS_TASK_MANAGER_H
#define ROS_TASK_MANAGER_H

#include <ros_standart.h>

namespace ROS {
    class TaskManager {
    public:
        static constexpr uint32_t CORES_FOR_TASKS = 3;
        static bool coresState[CORES_FOR_TASKS];
        static void (*tasks[CORES_FOR_TASKS]) ();

        static void addTask(IN void (*task) ());
    private:
        static uint32_t coreIndex;

        static void updateTasksIndex();
    };
}

#endif