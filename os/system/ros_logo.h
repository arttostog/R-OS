#ifndef ROS_OS_LOGO_H
#define ROS_OS_LOGO_H

#include <ros_standart.h>
#include <./drivers/ros_lfb.h>
#include <./utils/ros_image_from_bmp.h>

namespace ROS_OS {
    extern "C" const byte_t logo_pointer[];

    class Logo {
    public:
        enum Settings : uint32_t {
            LOGO_WIDTH = 32,
            LOGO_HEIGHT = 32
        };

        uint32_t logoBuffer[Logo::LOGO_WIDTH * Logo::LOGO_HEIGHT];
        ROS::Lfb::Image logoImage;

        Logo(const ROS::Lfb::Screen *screen);
        void show();
    };
}

#endif