#ifndef ROS_CLOCK_S_HPP
#define ROS_CLOCK_S_HPP

#include <ros_standart.hpp>

extern "C" {
    uint32_t clock_frequency(void);
    uint64_t clock_uptime(void);
}

#endif