#ifndef ROS_UART_INPUT_H
#define ROS_UART_INPUT_H

#include <ros_standart.h>
#include <./drivers/uart/ros_uart.h>

namespace ROS {
    class UartInput {
    public:
        static byte_t getByte();
    };
}

#endif