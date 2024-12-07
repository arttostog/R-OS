#ifndef ROS_UART_H
#define ROS_UART_H

#include <ros_standart.h>
#include <./drivers/gpio/ros_gpio.h>

namespace ROS {
    class Uart {
    public:
        enum : uint64_t {
            UART0_BASE = Gpio::GPIO_BASE + 0x1000,
            UART0_DR = UART0_BASE + 0x00,
            UART0_FR = UART0_BASE + 0x18,
        };

        static uint32_t read(IN uint64_t address);
        static void write(IN uint64_t address, IN uint32_t data);
    };
}

#endif