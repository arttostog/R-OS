#ifndef ROS_STRING_BUILDER_H
#define ROS_STRING_BUILDER_H

#include <ros_standart.h>
#include <./kernel/utils/string/ros_string.h>

namespace ROS {
    class StringBuilder {
    public:
        static constexpr uint32_t MAX_STRING_LENGTH = 512;

        char string[MAX_STRING_LENGTH];
        uint32_t stringLength;

        StringBuilder();

        void append(IN char symbol);
        void append(IN uint64_t number);
        void append(IN const char* string);
        void append(IN const char* string, IN uint32_t stringLength);
        void clean();
    };
}

#endif