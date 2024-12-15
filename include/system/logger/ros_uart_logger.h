#ifndef ROS_UART_LOGGER_H
#define ROS_UART_LOGGER_H

#include <ros_standart.h>
#include <./drivers/uart/ros_uart_output.h>
#include <./utils/string/ros_string.h>
#include <./utils/string/ros_string_builder.h>
#include <./drivers/clock/ros_clock.h>
#include <./boot/ros_boot.h>

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

            static void setClock(Clock* newClock);
            static void log(IN LogType logType, IN const char* string);
            static void log(IN LogType logType, IN const char* string, IN uint32_t stringSize);
        private:
            static Clock* clock;
            static bool isLogging;
    };
};

#endif