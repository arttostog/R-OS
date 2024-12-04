#ifndef ROS_OUTPUT_HPP
#define ROS_OUTPUT_HPP

#include <ros_standart.hpp>

#define UART0 ((byte_t*) 0x09000000)

namespace ROS {
    class Output {
        public:
            static void putByte(IN byte_t byte);
            static void putBytes(IN const byte_t* bytes);
    };
};

#endif