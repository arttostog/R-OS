#ifndef ROS_CONSOLE_HANDLER_H
#define ROS_CONSOLE_HANDLER_H

#include <./kernel/drivers/lfb/ros_lfb.h>
#include <./os/system/font/ros_font.h>
#include <./kernel/utils/color/ros_color.h>
#include <./kernel/drivers/task-manager/ros_task_manager.h>
#include <./kernel/drivers/clock/ros_clock.h>
#include <./os/system/logo/ros_logo.h>

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