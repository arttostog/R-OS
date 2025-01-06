#ifndef ROS_UART_OUTPUT_H
#define ROS_UART_OUTPUT_H

#include <ros_standart.h>
#include <./drivers/uart/ros_uart.h>

namespace ROS {
    class UartOutput {
        public:
            static void putByte(IN byte_t byte);
            static void putBytes(IN const byte_t* bytes, IN uint32_t bytesCount);
        private:
            static bool isBusy;
    };
};

#endif