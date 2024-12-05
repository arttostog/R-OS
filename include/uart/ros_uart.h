#ifndef ROS_UART_H
#define ROS_UART_H

#include <ros_standart.h>

#define GPIO_BASE ((byte_t*) 0x200000)

#define UART0_BASE (GPIO_BASE + 0x1000)

#define UART0_DR (UART0_BASE + 0x00)
#define UART0_FR (UART0_BASE + 0x18)

#define MMIO_BASE 0x3F000000

namespace ROS {
    class Uart {
    public:
        static byte_t read(IN byte_t* address);
        static void write(IN byte_t* address, IN byte_t data);
    };
}

#endif