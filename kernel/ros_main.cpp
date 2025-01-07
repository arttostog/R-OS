#include <./drivers/uart/ros_uart.h>
#include <./drivers/lfb/ros_lfb.h>
#include <./drivers/clock/ros_clock.h>
#include <./os/ros_os_main.h>
#include <./drivers/task-manager/ros_task_manager.h>

using namespace ROS;

extern "C" {
    void kernel_start() {
        Clock::init();
        Uart::init();
        Lfb::init();

        OsMain::start();
    }

    void kernel_loop() {
        OsMain::loop();
    }
}