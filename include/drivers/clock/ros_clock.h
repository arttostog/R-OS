#ifndef ROS_CLOCK_H
#define ROS_CLOCK_H

#include <ros_standart.h>
#include <./drivers/clock/ros_clock_s.h>
#include <./utils/ros_uart_logger.h>

namespace ROS {
    class Clock {
        public:
            Clock();
            uint32_t getFrequency();
            uint64_t getUptime();
            void delay(IN float64_t seconds);
        private:
            const static uint64_t mhz = 1000000,
                nanosecondsInSecond = 1000000000;
            uint64_t clockFrequency;
    };
};

#endif