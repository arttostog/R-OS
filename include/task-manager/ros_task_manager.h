#ifndef ROS_TASK_MANAGER_H
#define ROS_TASK_MANAGER_H

#include <ros_standart.h>
#include <./uart/ros_uart_output.h>
#include <./utils/ros_string.h>

#define CORES_FOR_TASKS 3

extern "C" {
    extern void (*tasks[CORES_FOR_TASKS]) ();
}

#endif