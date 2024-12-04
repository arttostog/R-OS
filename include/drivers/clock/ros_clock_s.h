#ifndef ROS_CLOCK_S_H
#define ROS_CLOCK_S_H

#include <ros_standart.h>

extern "C" {
    uint32_t clock_frequency();
    uint64_t clock_uptime();
}

#endif