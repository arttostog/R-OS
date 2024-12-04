#ifndef ROS_UART_INPUT_H
#define ROS_UART_INPUT_H

#include <ros_standart.h>
#include <./uart/ros_uart.h>

namespace ROS {
    class Input {
    public:
        static byte_t getByte();
    };
}

#endif