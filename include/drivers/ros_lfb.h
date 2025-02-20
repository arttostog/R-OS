#ifndef ROS_LFB_H
#define ROS_LFB_H

#include <ros_standart.h>
#include <./utils/ros_uart_logger.h>
#include <./utils/ros_color.h>
#include "ros_clock.h"
#include "ros_mailbox.h"

namespace ROS {
    
    class Lfb {
    public:
        struct Screen {
            uint32_t width, height, pitch;
            bool isRgb;
        };

        struct Image {
            uint32_t* image, imageWidth, imageHeight, imageStartPixelPosition, imageNewLine;
        };

        static void init();
        static void show(IN const Image* imageToShow);
        static void clearScreen();
        static void fillScreen(IN uint32_t color);
        static const Screen* getScreen();
    private:
        static Screen screen;
        static void* lfb;

        static uint32_t convertColor(IN uint32_t color);
    };
}

#endif