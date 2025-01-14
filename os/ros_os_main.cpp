#include <./kernel/drivers/lfb/ros_lfb.h>
#include <./os/services/console/ros_console_handler.h>
#include <./os/services/uart-console/ros_uart_console_handler.h>
#include <./kernel/drivers/task-manager/ros_task_manager.h>

using namespace ROS;

void os_start() {
    ConsoleHandler::init();
    UartConsoleHandler::init();
}

void os_loop() {
    UartConsoleHandler::handle();
}