#include "./services/ros_console_handler.h"
#include "./services/ros_uart_console_handler.h"

using ROS_OS::ConsoleHandler, ROS_OS::UartConsoleHandler;

void os_start() {
    ConsoleHandler::init();
    UartConsoleHandler::init();
}

void os_loop() {
    UartConsoleHandler::handle();
}