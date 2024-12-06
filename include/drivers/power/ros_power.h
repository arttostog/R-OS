#ifndef ROS_POWER_H
#define ROS_POWER_H

#include <./drivers/power/ros_power_s.h>
#include <./drivers/task-manager/ros_task_manager.h>
#include <./boot/ros_boot.h>

namespace ROS {
    class Power {
    public:
        static void shutdown();
        static void softReset();
    };
}

#endif