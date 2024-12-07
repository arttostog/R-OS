#ifndef ROS_CLOCK_H
#define ROS_CLOCK_H

#include <ros_standart.h>
#include <./drivers/clock/ros_clock_s.h>
#include <./utils/ros_uart_logger.h>

namespace ROS {
    class Clock {
        public:
            const static uint64_t MHZ = 1000000,
                NANOSECONDS_IN_SECOND = 1000000000;

            Clock();
            uint32_t getFrequency();
            uint64_t getUptime();
            void delay(IN float64_t seconds);
            void delayByCycles(IN uint64_t cycles);
        private:
            uint64_t clockFrequency;
    };
};

#endif