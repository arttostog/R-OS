#include <./drivers/uart/ros_uart_input.h>

using namespace ROS;

byte_t Input::getByte() {
    while (Uart::read(UART0_FR) & (1 << 4))
        continue;
    return Uart::read(UART0_DR);
}