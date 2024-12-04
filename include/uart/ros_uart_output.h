#ifndef ROS_UART_OUTPUT_H
#define ROS_UART_OUTPUT_H

#include <ros_standart.h>
#include <./uart/ros_uart.h>

namespace ROS {
    class Output {
        public:
            static void putByte(IN byte_t byte);
            static void putBytes(IN const byte_t* bytes, IN uint32_t bytesCount);
    };
};

#endif