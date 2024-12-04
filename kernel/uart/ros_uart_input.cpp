#include <./uart/ros_uart_input.h>

using ROS::Input;

byte_t Input::getByte() {
    while (UARTRFR & 0x10)
        continue;
    return UARTDR;
}