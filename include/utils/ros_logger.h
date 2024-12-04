#ifndef ROS_LOGGER_H
#define ROS_LOGGER_H

#include <ros_standart.h>
#include <ros_output.h>
#include <./utils/ros_string.h>

namespace ROS {
    class Logger
    {
        public:
            typedef enum {
                INFO,
                WARN,
                ERROR
            } LogType;
            static void log(IN LogType logType, IN const char* string);
            static void log(IN LogType logType, IN const char* string, IN uint32_t stringSize);
        private:
            static void logStart(IN LogType logType);
            static const char* convertLogTypeToString(IN LogType logType);
    };
};

#endif