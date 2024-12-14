#ifndef ROS_FONT_H
#define ROS_FONT_H

#include <ros_standart.h>
#include <./drivers/lfb/ros_lfb.h>
#include <./utils/font/ros_font_s.h>

namespace ROS {
    class Lfb;

    class Font {
    public:
        static const uint32_t FONT_SYMBOL_WIDTH = 5,
            FONT_SYMBOL_HEIGHT = 7;

        static void getSymbolAsImage(Image* image, char symbol);
    private:
        static const uint32_t* symbolPointer;
        static uint32_t symbolImage[FONT_SYMBOL_HEIGHT * FONT_SYMBOL_WIDTH];
        static const uint32_t NEW_LINE_MARGIN = FONT_SYMBOL_WIDTH * 128;
    };
}

#endif