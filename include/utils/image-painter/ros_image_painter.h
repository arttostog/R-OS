#ifndef ROS_IMAGE_PAINTER_H
#define ROS_IMAGE_PAINTER_H

#include <ros_standart.h>
#include <./drivers/lfb/ros_lfb.h>

namespace ROS {
    class Lfb;

    class ImagePainter {
    public:
        enum Color : uint32_t {
            BLACK = 0x000000FF,
            BLUE = 0x0000AAFF,
            GREEN = 0x00AA00FF,
            CYAN = 0x00AAAAFF,
            RED = 0xAA0000FF,
            MAGENTA = 0xAA00AAFF,
            BROWN = 0xAA5500FF,
            WHITE = 0xAAAAAAFF,
            GRAY = 0x555555FF,
            LIGHT_BLUE = 0x5555FFFF,
            LIGHT_GREEN = 0x55FF55FF,
            LIGHT_CYAN = 0x55FFFFFF,
            LIGHT_RED = 0xFF5555FF,
            LIGHT_MAGENTA = 0xFF55FFFF,
            YELLOW = 0xFFFF55FF,
            BRIGHT_WHITE = 0xFFFFFFFF
        };

        static void drawPixel(OUT Image* image, IN uint32_t pixelPosition, IN uint32_t color);
        static void drawPixels(OUT Image* image, IN uint32_t startPixelPosition, IN uint32_t endPixelPosition, IN uint32_t color);
    };
}

#endif