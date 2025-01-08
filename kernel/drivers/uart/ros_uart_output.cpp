#include <./drivers/uart/ros_uart_output.h>

using namespace ROS;

bool UartOutput::isBusy = false;

void UartOutput::putByte(IN byte_t byte) {
    while (Uart::read(Uart::UART0_FR) & (1 << 5))
        continue;
    Uart::write(Uart::UART0_DR, byte);
}

void UartOutput::putBytes(IN const byte_t* bytes, IN uint32_t bytesCount) {
    while (isBusy)
        continue;
    
    isBusy = true;

    for (uint32_t i = 0; i < bytesCount; ++i)
        putByte(bytes[i]);
    
    isBusy = false;
}