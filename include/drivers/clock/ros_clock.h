#ifndef ROS_CLOCK_H
#define ROS_CLOCK_H

#include <ros_standart.h>
#include <./system/logger/ros_uart_logger.h>

namespace ROS {
    extern "C" {
        uint32_t clock_frequency();
        uint64_t clock_uptime();
    }

    class Clock {
        public:
            static constexpr uint64_t MHZ = 1000000,
                NANOSECONDS_IN_SECOND = 1000000000;

            static void init();
            static uint32_t getFrequency();
            static uint64_t getUptime();
            static void delay(IN float64_t seconds);
            
            static void delayByCycles(IN uint64_t cycles);
        private:
            static uint64_t clockFrequency;
    };
};

#endif