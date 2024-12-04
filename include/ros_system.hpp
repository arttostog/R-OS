#ifndef ROS_SYSTEM_HPP
#define ROS_SYSTEM_HPP

#include <ros_standart.hpp>

extern "C" {
    uint32_t clock_frequency(void);
    uint64_t clock_uptime(void);
    void shutdown(void);
}

#endif