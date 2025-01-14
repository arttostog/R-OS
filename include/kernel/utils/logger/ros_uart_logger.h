#ifndef ROS_UART_LOGGER_H
#define ROS_UART_LOGGER_H

#include <ros_standart.h>
#include <./kernel/drivers/uart/ros_uart_output.h>
#include <./kernel/utils/string/ros_string.h>
#include <./kernel/utils/string/ros_string_builder.h>
#include <./kernel/drivers/clock/ros_clock.h>
#include <./kernel/boot/ros_boot.h>

namespace ROS {
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
    };
};

#endif