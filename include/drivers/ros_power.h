#ifndef ROS_POWER_H
#define ROS_POWER_H

#include <ros_standart.h>
#include <./utils/ros_uart_logger.h>
#include "ros_mailbox.h"
#include "ros_gpio.h"
#include "ros_clock.h"

namespace ROS {
    class Power {
    public:
        static void shutdown();
    private:
        enum PowerMode : uint64_t {
            POWER_MODE_RSTC = Gpio::MMIO_BASE + 0x10001C,
            POWER_MODE_RSTS = Gpio::MMIO_BASE + 0x100020,
            POWER_MODE_WDOG = Gpio::MMIO_BASE + 0x100024,
            POWER_MODE_WDOG_MAGIC = 0x5a000000,
            POWER_MODE_RSTC_FULL_RESET = 0x00000020
        };
    };
}

#endif