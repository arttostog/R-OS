#ifndef ROS_CONVERTER_HPP
#define ROS_CONVERTER_HPP

#include "ros_standart.hpp"

namespace ROS {
    class Converter {
    public:
        static void numberToString(IN uint64_t number, OUT char* buffer, IN int32_t bufferSize);
    };
}

#endif