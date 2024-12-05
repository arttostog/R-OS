#include <./uart/ros_uart.h>

using ROS::Uart;

byte_t Uart::read(IN byte_t* address){
    return *(MMIO_BASE + address);
}

void Uart::write(IN byte_t* address, IN byte_t data) {
    *(MMIO_BASE + address) = data;
}