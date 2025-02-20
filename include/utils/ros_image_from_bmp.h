#ifndef ROS_IMAGE_FROM_BMP_H
#define ROS_IMAGE_FROM_BMP_H

#include <ros_standart.h>
#include <./drivers/ros_lfb.h>

namespace ROS {
    class Lfb;

    class ImageFromBmp {
    public:
        static void get(OUT Lfb::Image* image, IN const void* bmp, IN uint32_t bmpStartIndex, IN uint32_t newLineMargin);
    };
}

#endif