#ifndef ROS_POWER_H
#define ROS_POWER_H

#include <ros_standart.h>
#include <./drivers/mailbox/ros_mailbox.h>
#include <./drivers/gpio/ros_gpio.h>
#include <./drivers/clock/ros_clock.h>
#include <./system/logger/ros_uart_logger.h>

namespace ROS {
    class Power {
    public:
        static void shutdown();
        static void softReset();
    private:
        enum : uint64_t {
            PM_RSTC = Gpio::MMIO_BASE + 0x10001C,
            PM_RSTS = Gpio::MMIO_BASE + 0x100020,
            PM_WDOG = Gpio::MMIO_BASE + 0x100024,
            PM_WDOG_MAGIC = 0x5a000000,
            PM_RSTC_FULL_RESET = 0x00000020
        };

        static void updatePm(uint64_t newPmRsts);
    };
}

#endif