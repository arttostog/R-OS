#include <./drivers/ros_uart_input.h>

using namespace ROS;

byte_t UartInput::getByte() {
    return Uart::read(Uart::UART0_FR) & (1 << 4) ? 0 : Uart::read(Uart::UART0_DR);
}