#ifndef ROS_BOOT_H
#define ROS_BOOT_H

#include <ros_standart.h>

extern "C" {
    void _start();
    uint64_t get_current_core();
}

#endif