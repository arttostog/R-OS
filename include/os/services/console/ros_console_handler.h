#ifndef ROS_CONSOLE_HANDLER_H
#define ROS_CONSOLE_HANDLER_H

#include <./drivers/lfb/ros_lfb.h>
#include <./os/system/font/ros_font.h>
#include <./utils/color/ros_color.h>

namespace ROS {
    class ConsoleHandler {
    public:
        static void init();
        static void handle();
    };
}

#endif