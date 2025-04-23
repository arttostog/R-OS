#ifndef ROS_UART_LOGGER_H
#define ROS_UART_LOGGER_H

#include <ros_standart.h>
#include <./drivers/ros_uart_output.h>
#include <./drivers/ros_clock.h>
#include <./drivers/ros_cores.h>
#include "ros_string.h"
#include "ros_string_builder.h"
#include "ros_queue.h"

namespace ROS {
    class Queue;
    class Clock;

    class Logger
    {
        public:
            enum LogType : char {
                SUCCESS = 'S',
                INFO = 'I',
                WARN = 'W',
                ERROR = 'E'
            };
            
            static void log(IN LogType logType, IN const char* string);
            static void log(IN LogType logType, IN const char* string, IN uint32_t stringSize);
        private:
            static bool isBusy;
            static StringBuilder builder;
            static Queue queue;
    };
};

#endif