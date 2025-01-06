#ifndef ROS_OS_MAIN
#define ROS_OS_MAIN

#include <./drivers/lfb/ros_lfb.h>
#include <./os/system/logo/ros_logo.h>
#include <./os/services/uart-console/ros_uart_console_handler.h>

namespace ROS {
    class OsMain {
    public:
        static void start();
        static void loop();
    };
}

#endif