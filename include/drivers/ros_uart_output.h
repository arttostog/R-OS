#ifndef ROS_UART_OUTPUT_H
#define ROS_UART_OUTPUT_H

#include <ros_standart.h>
#include <./utils/ros_queue.h>
#include "ros_uart.h"

namespace ROS {
    class Queue;
    
    class UartOutput {
        public:
            static void putBytes(IN const byte_t* bytes, IN uint32_t bytesCount);
        private:
            static Queue queue;

            static void putByte(IN byte_t byte);
    };
};

#endif