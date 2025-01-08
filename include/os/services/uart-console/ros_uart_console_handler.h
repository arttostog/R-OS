#ifndef ROS_CONSOLE_HANDLER_H
#define ROS_CONSOLE_HANDLER_H

#include <ros_standart.h>
#include <./os/services/uart-console/commands/ros_uart_console_handler_commands.h>
#include <./drivers/uart/ros_uart_output.h>
#include <./drivers/uart/ros_uart_input.h>
#include <./utils/string/ros_string.h>
#include <./drivers/task-manager/ros_task_manager.h>

namespace ROS {
    class UartConsoleHandler {
    public:
        static void init();
        static void handle();
    private:
        static constexpr int32_t INPUT_BUFFER_SIZE = 64;

        static byte_t inputBuffer[INPUT_BUFFER_SIZE];
        static int32_t inputLength;

        static void commandHandler();
        static void clearInputBuffer();
    };
}

#endif