#ifndef ROS_LOGGER_HPP
#define ROS_LOGGER_HPP

#include <ros_standart.hpp>
#include <ros_output.hpp>
#include <./utils/ros_string.hpp>

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