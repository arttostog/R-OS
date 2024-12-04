#include <./uart0/ros_uart0_output.h>

using ROS::Output;

void Output::putByte(IN byte_t byte) {
    while (UARTRFR & 0x20)
        continue;
    UARTDR = byte;
}

void Output::putBytes(IN const byte_t* bytes, IN uint32_t bytesCount) {
    for (uint32_t i = 0; i < bytesCount; ++i)
        putByte(bytes[i]);
}