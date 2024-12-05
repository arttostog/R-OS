#ifndef ROS_STRING_H
#define ROS_STRING_H

#include <ros_standart.h>

namespace ROS {
    class String {
    public:
        static void numberToString(IN uint64_t number, OUT char* buffer, IN int32_t bufferSize, IN bool cleanFirstZeros);
        static uint32_t getStringSize(IN const char* string);
    };
}

#endif