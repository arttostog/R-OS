#ifndef ROS_FONT_H
#define ROS_FONT_H

#include <ros_standart.h>
#include <./drivers/lfb/ros_lfb.h>
#include <./utils/image-from-bmp/ros_image_from_bmp.h>

namespace ROS {
    class Lfb;

    extern "C" const byte_t font_pointer[];
    class Font {
    public:
        enum Settings : uint32_t {
            FONT_SYMBOL_WIDTH = 5,
            FONT_SYMBOL_HEIGHT = 7,
            NEW_LINE_MARGIN = FONT_SYMBOL_WIDTH * 128
        };

        static void getSymbolAsImage(OUT Lfb::Image* image, OUT uint32_t symbolBuffer[FONT_SYMBOL_HEIGHT * FONT_SYMBOL_WIDTH], IN char symbol);
    private:
        static uint32_t symbolImage[FONT_SYMBOL_HEIGHT * FONT_SYMBOL_WIDTH];
    };
}

#endif