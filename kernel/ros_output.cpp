#include <ros_output.hpp>

void ROS::Output::putByte(IN byte_t byte) {
    *UART0 = byte;
}

void ROS::Output::putBytes(IN const byte_t* bytes) {
    for (; *bytes != '\0'; ++bytes)
        putByte(*bytes);
}