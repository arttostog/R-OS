#ifndef ROS_CONVERTER_HPP
#define ROS_CONVERTER_HPP

#include <ros_standart.hpp>

namespace ROS {
    class String {
    public:
        static void numberToString(IN uint64_t number, OUT char* buffer, IN int32_t bufferSize, IN bool cleanFirstZeros);
        static uint32_t getStringSize(IN const char* string);
    };
}

#endif