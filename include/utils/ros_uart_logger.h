#ifndef ROS_UART_LOGGER_H
#define ROS_UART_LOGGER_H

#include <ros_standart.h>
#include <./drivers/uart/ros_uart_output.h>
#include <./utils/ros_string.h>
#include <./drivers/clock/ros_clock.h>
#include <./boot/ros_boot.h>

namespace ROS {
    class Logger
    {
        public:
            typedef enum {
                INFO,
                WARN,
                ERROR
            } LogType;

            ROS::Clock* clock;
            
            Logger();
            Logger(IN ROS::Clock* clock);

            void log(IN LogType logType, IN const char* string);
            void log(IN LogType logType, IN const char* string, IN uint32_t stringSize);
        private:
            bool isLogging;
            const char* convertLogTypeToString(IN LogType logType);
    };
};

#endif