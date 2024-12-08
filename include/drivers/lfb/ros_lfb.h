#ifndef ROS_LFB_H
#define ROS_LFB_H

#include <ros_standart.h>
#include <./drivers/clock/ros_clock.h>
#include <./drivers/mailbox/ros_mailbox.h>
#include <./utils/logger/ros_uart_logger.h>

namespace ROS {
    class Clock;

    struct Image {
        uint32_t* image, imageWidth, imageHeight;
    };

    class Lfb {
    public:
        Lfb(IN Clock* clock);
        void show(IN const Image* imageToShow);
    private:
        uint32_t width, height, pitch;
        bool isRgb;
        byte_t* lfb;
    };
}

#endif