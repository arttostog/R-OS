#include <./kernel/drivers/uart/ros_uart.h>
#include <./kernel/drivers/lfb/ros_lfb.h>
#include <./kernel/drivers/clock/ros_clock.h>
#include <./kernel/drivers/task-manager/ros_task_manager.h>

using namespace ROS;

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