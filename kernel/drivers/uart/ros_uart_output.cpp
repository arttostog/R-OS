#include <./drivers/uart/ros_uart_output.h>

using namespace ROS;

bool Output::isBusy = false;

void Output::putByte(IN byte_t byte) {
    while (Uart::read(Uart::UART0_FR) & (1 << 5))
        continue;
    Uart::write(Uart::UART0_DR, byte);
}

void Output::putBytes(IN const byte_t* bytes, IN uint32_t bytesCount) {
    while (isBusy)
        continue;
    
    isBusy = true;

    for (uint32_t i = 0; i < bytesCount; ++i)
        putByte(bytes[i]);
    
    isBusy = false;
}