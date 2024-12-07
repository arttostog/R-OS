#ifndef ROS_STRING_BUILDER_H
#define ROS_STRING_BUILDER_H

#include <ros_standart.h>
#include <./utils/string/ros_string.h>

namespace ROS {
    class StringBuilder {
    public:
        static const uint32_t MAX_STRING_LENGTH = 127;

        char string[MAX_STRING_LENGTH + 1];
        uint32_t stringLength;

        StringBuilder();

        void append(const char* string);
        void append(char symbol);
        void append(const char* string, uint32_t stringLength);
    };
}

#endif