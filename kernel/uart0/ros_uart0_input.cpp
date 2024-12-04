#include <./uart0/ros_uart0_input.h>

using ROS::Input;

byte_t Input::getByte() {
    while (UARTRFR & 0x10)
        continue;
    return UARTDR;
}