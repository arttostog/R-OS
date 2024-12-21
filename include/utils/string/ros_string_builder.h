#ifndef ROS_STRING_BUILDER_H
#define ROS_STRING_BUILDER_H

#include <ros_standart.h>
#include <./utils/string/ros_string.h>

namespace ROS {
    class StringBuilder {
    public:
        static constexpr uint32_t MAX_STRING_LENGTH = 511;

        char string[MAX_STRING_LENGTH + 1];
        uint32_t stringLength;

        StringBuilder();

        void append(IN const char* string);
        void append(IN char symbol);
        void append(IN const char* string, uint32_t stringLength);
    };
}

#endif