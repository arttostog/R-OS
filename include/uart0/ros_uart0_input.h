#ifndef ROS_UART0_INPUT_H
#define ROS_UART0_INPUT_H

#include <ros_standart.h>
#include <./uart0/ros_uart0.h>

namespace ROS {
    class Input {
    public:
        static byte_t getByte();
    };
}

#endif