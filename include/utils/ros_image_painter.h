#ifndef ROS_IMAGE_PAINTER_H
#define ROS_IMAGE_PAINTER_H

#include <ros_standart.h>
#include <./drivers/ros_lfb.h>

namespace ROS {
    class Lfb;

    class ImagePainter {
    public:
        static void drawPixel(OUT Lfb::Image* image, IN uint32_t pixelPosition, IN uint32_t color);
        static void drawPixels(OUT Lfb::Image* image, IN uint32_t startPixelPosition, IN uint32_t endPixelPosition, IN uint32_t color);
    };
}

#endif