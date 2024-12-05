#ifndef ROS_CLOCK_H
#define ROS_CLOCK_H

#include <ros_standart.h>
#include <./drivers/clock/ros_clock_s.h>
#include <./utils/ros_uart_logger.h>

#define MHZ 1000000
#define NANOSECONDS_IN_SECOND 1000000000

namespace ROS {
    class Clock {
        public:
            Clock();
            uint32_t getFrequency();
            uint64_t getUptime();
        private:
            uint64_t clockFrequency;
    };
};

#endif