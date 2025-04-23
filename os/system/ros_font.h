#ifndef ROS_OS_FONT_H
#define ROS_OS_FONT_H

#include <ros_standart.h>
#include <./drivers/ros_lfb.h>
#include <./utils/ros_image_from_bmp.h>

namespace ROS_OS {
    extern "C" const byte_t font_pointer[];

    class Font {
    public:
        enum Settings : uint32_t {
            FONT_SYMBOL_WIDTH = 5,
            FONT_SYMBOL_HEIGHT = 7,
            FONT_SYMBOL_SIZE = FONT_SYMBOL_WIDTH * FONT_SYMBOL_HEIGHT,
            NEW_LINE_MARGIN = FONT_SYMBOL_WIDTH * 128
        };

        static void getSymbolAsImage(OUT ROS::Lfb::Image* image, OUT uint32_t symbolBuffer[FONT_SYMBOL_SIZE], IN char symbol);
    };
}

#endif