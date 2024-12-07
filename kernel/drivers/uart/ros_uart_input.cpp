#include <./drivers/uart/ros_uart_input.h>

using namespace ROS;

byte_t Input::getByte() {
    while (Uart::read(Uart::UART0_FR) & (1 << 4))
        continue;
    return Uart::read(Uart::UART0_DR);
}