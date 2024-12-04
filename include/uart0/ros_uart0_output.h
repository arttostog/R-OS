#ifndef ROS_OUTPUT_H
#define ROS_OUTPUT_H

#include <ros_standart.h>
#include <./uart0/ros_uart0.h>

namespace ROS {
    class Output {
        public:
            static void putByte(IN byte_t byte);
            static void putBytes(IN const byte_t* bytes, IN uint32_t bytesCount);
    };
};

#endif