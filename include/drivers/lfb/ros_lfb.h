#ifndef ROS_LFB_H
#define ROS_LFB_H

#include <ros_standart.h>
#include <./drivers/clock/ros_clock.h>
#include <./drivers/mailbox/ros_mailbox.h>
#include <./system/logger/ros_uart_logger.h>

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

        Lfb();
        
        void show(IN const Image* imageToShow);

        Screen getScreen() const;
    private:
        Screen screen;
        byte_t* lfb;
    };
}

#endif