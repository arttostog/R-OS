#ifndef ROS_LOGGER_HPP
#define ROS_LOGGER_HPP

#include "ros_standart.hpp"
#include "ros_output.hpp"
#include "./drivers/ros_clock.hpp"

namespace ROS {
    class Logger
    {
        public:
            typedef enum {
                INFO,
                WARN,
                ERROR
            } LogType;
            static void log(IN LogType type, IN const char* message);
        private:
            static const char* convertLogTypeToString(IN LogType type);
    };
};

#endif