#ifndef ROS_UART_H
#define ROS_UART_H

#include <ros_standart.h>
#include <./drivers/gpio/ros_gpio.h>
#include <./drivers/mailbox/ros_mailbox.h>
#include <./drivers/clock/ros_clock.h>
#include <./system/logger/ros_uart_logger.h>

namespace ROS {
    class Uart {
    public:
        enum Uart0 : uint64_t {
            UART0_BASE = Gpio::GPIO_PLUS_MMIO_BASES + 0x1000,
            
            UART0_DR = UART0_BASE + 0x00,
            UART0_FR = UART0_BASE + 0x18,
            UART0_IBRD = UART0_BASE + 0x24,
            UART0_FBRD = UART0_BASE + 0x28,
            UART0_LCRH = UART0_BASE + 0x2C,
            UART0_CR = UART0_BASE + 0x30,
            UART0_IMSC = UART0_BASE + 0x38,
            UART0_ICR = UART0_BASE + 0x44
        };

        static void init();
        static uint32_t read(IN uint64_t address);
        static void write(IN uint64_t address, IN uint32_t data);
    };
}

#endif