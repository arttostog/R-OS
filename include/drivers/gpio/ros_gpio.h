#ifndef ROS_GPIO_H
#define ROS_GPIO_H

#include <ros_standart.h>

namespace ROS {
    class Gpio {
        public:
            static const uint64_t GPIO_BASE = 0x200000,
                MMIO_BASE = 0x3F000000;
    };
}

#endif