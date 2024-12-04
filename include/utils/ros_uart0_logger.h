#ifndef ROS_LOGGER_H
#define ROS_LOGGER_H

#include <ros_standart.h>
#include <./uart0/ros_uart0_output.h>
#include <./utils/ros_string.h>
#include <./drivers/clock/ros_clock.h>

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
            void logStart(IN LogType logType);
            const char* convertLogTypeToString(IN LogType logType);
    };
};

#endif