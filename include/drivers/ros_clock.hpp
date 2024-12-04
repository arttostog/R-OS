#ifndef ROS_CLOCK_HPP
#define ROS_CLOCK_HPP

#include "ros_standart.hpp"
#include "ros_system.hpp"
#include "ros_logger.hpp"

#define MHZ 1000000
#define NANOSECONDS_IN_SECOND 1000000000

namespace ROS {
    class Clock {
        public:
            Clock(void);
            uint32_t getFrequency(void);
            uint64_t getUptime(void);
        private:
            uint64_t clockFrequency;
    };
};

#endif