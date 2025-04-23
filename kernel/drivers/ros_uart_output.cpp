#include <./drivers/ros_uart_output.h>

using ROS::UartOutput, ROS::Queue, ROS::Uart;

Queue UartOutput::queue = Queue();

void UartOutput::putByte(IN byte_t byte) {
    while (Uart::read(Uart::UART0_FR) & (1 << 5))
        continue;
    Uart::write(Uart::UART0_DR, byte);
}

void UartOutput::putBytes(IN const byte_t* bytes, IN uint32_t bytesCount) {
    queue.wait(queue.getInLine());

    for (uint32_t i = 0; i < bytesCount; ++i)
        putByte(bytes[i]);
    
    queue.stepOutOfLine();
}