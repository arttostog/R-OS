#ifndef ROS_LOGO_H
#define ROS_LOGO_H

#include <ros_standart.h>

namespace ROS {
    extern "C" const byte_t logo_pointer[];

    class Logo {
    public:
        static const uint32_t LOGO_WIDTH = 32,
            LOGO_HEIGHT = 32;
    };
}

#endif