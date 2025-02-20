#ifndef ROS_CONSOLE_HANDLER_H
#define ROS_CONSOLE_HANDLER_H

#include <./drivers/ros_lfb.h>
#include <./utils/ros_color.h>
#include <./drivers/ros_task_manager.h>
#include <./drivers/ros_clock.h>
#include "../system/ros_font.h"
#include "../system/ros_logo.h"

namespace ROS {
    class ConsoleHandler {
    public:
        static void init();
    private:
        static uint32_t symbolBuffer[Font::FONT_SYMBOL_SIZE];
        static Lfb::Image symbolImage;

        static void handle();
    };
}

#endif