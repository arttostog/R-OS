#ifndef ROS_LOGO_H
#define ROS_LOGO_H

#include <ros_standart.h>
#include <./kernel/drivers/lfb/ros_lfb.h>
#include <./kernel/utils/image-from-bmp/ros_image_from_bmp.h>

namespace ROS {
    class Lfb;
    
    extern "C" const byte_t logo_pointer[];

    class Logo {
    public:
        enum Settings : uint32_t {
            LOGO_WIDTH = 32,
            LOGO_HEIGHT = 32
        };

        uint32_t logoBuffer[Logo::LOGO_WIDTH * Logo::LOGO_HEIGHT];
        Lfb::Image logoImage;

        Logo(const Lfb::Screen* screen);
        void show();
    };
}

#endif