#ifndef ROS_UART_CONSOLE_HANDLER_H
#define ROS_UART_CONSOLE_HANDLER_H

#include <ros_standart.h>
#include <./os/services/uart-console/commands/ros_uart_console_handler_commands.h>
#include <./kernel/drivers/uart/ros_uart_output.h>
#include <./kernel/drivers/uart/ros_uart_input.h>
#include <./kernel/utils/string/ros_string.h>
#include <./kernel/drivers/task-manager/ros_task_manager.h>

namespace ROS {
    class UartConsoleHandler {
    public:
        static void init();
        static void handle();
    private:
        static constexpr uint32_t INPUT_BUFFER_SIZE = 64;

        static byte_t inputBuffer[INPUT_BUFFER_SIZE];
        static uint32_t inputLength;

        static void commandHandler();
        static void clearInputBuffer();
    };
}

#endif