#ifndef ROS_UART_H
#define ROS_UART_H

#include <ros_standart.h>

namespace ROS {
    class Uart {
    public:
        enum {
            GPIO_BASE = 0x200000,
            UART0_BASE = GPIO_BASE + 0x1000,
            UART0_DR = UART0_BASE + 0x00,
            UART0_FR = UART0_BASE + 0x18,
            MMIO_BASE = 0x3F000000
        };

        static uint32_t read(IN uint64_t address);
        static void write(IN uint64_t address, IN uint32_t data);
    };
}

#endif