#include <./drivers/ros_uart.h>
#include <./drivers/ros_lfb.h>
#include <./drivers/ros_clock.h>
#include <./drivers/ros_task_manager.h>

using ROS::Clock, ROS::Uart, ROS::Lfb;

extern void os_start();
extern void os_loop();

extern "C" {
    void kernel_start() {
        Clock::init();
        Uart::init();
        Lfb::init();

        os_start();
    }

    void kernel_loop() {
        os_loop();
    }
}