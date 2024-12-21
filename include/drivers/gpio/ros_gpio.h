#ifndef ROS_GPIO_H
#define ROS_GPIO_H

#include <ros_standart.h>

namespace ROS {
    class Gpio {
        public:
            enum Address : uint64_t {
                GPIO_BASE = 0x200000,
                MMIO_BASE = 0x3F000000,
                GPIO_PLUS_MMIO_BASES = GPIO_BASE + MMIO_BASE,

                GPFSEL0 = GPIO_PLUS_MMIO_BASES + 0x00,
                GPFSEL1 = GPIO_PLUS_MMIO_BASES + 0x04,
                GPFSEL2 = GPIO_PLUS_MMIO_BASES + 0x08,
                GPFSEL3 = GPIO_PLUS_MMIO_BASES + 0x0C,
                GPFSEL4 = GPIO_PLUS_MMIO_BASES + 0x10,
                GPFSEL5 = GPIO_PLUS_MMIO_BASES + 0x14,
                GPSET0 = GPIO_PLUS_MMIO_BASES + 0x1C,
                GPSET1 = GPIO_PLUS_MMIO_BASES + 0x20,
                GPCLR0 = GPIO_PLUS_MMIO_BASES + 0x28,
                GPLEV0 = GPIO_PLUS_MMIO_BASES + 0x34,
                GPLEV1 = GPIO_PLUS_MMIO_BASES + 0x38,
                GPEDS0 = GPIO_PLUS_MMIO_BASES + 0x40,
                GPEDS1 = GPIO_PLUS_MMIO_BASES + 0x44,
                GPHEN0 = GPIO_PLUS_MMIO_BASES + 0x64,
                GPHEN1 = GPIO_PLUS_MMIO_BASES + 0x68,
                GPPUD = GPIO_PLUS_MMIO_BASES + 0x94,
                GPPUDCLK0 = GPIO_PLUS_MMIO_BASES + 0x98,
                GPPUDCLK1 = GPIO_PLUS_MMIO_BASES + 0x9C
            };
    };
}

#endif