#include <./uart/ros_uart.h>

using namespace ROS;

uint32_t Uart::read(IN uint64_t address){
    return *(volatile uint32_t*) (MMIO_BASE + address);
}

void Uart::write(IN uint64_t address, IN uint32_t data) {
    *(volatile uint32_t*) (MMIO_BASE + address) = data;
}