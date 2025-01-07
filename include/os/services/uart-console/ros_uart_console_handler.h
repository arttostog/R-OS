#ifndef ROS_CONSOLE_HANDLER_H
#define ROS_CONSOLE_HANDLER_H

#include <ros_standart.h>
#include <./drivers/power/ros_power.h>
#include <./utils/logger/ros_uart_logger.h>
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
        static constexpr int32_t COMMANDS_COUNT = 2,
            INPUT_BUFFER_SIZE = 64;

        struct Command {
            const byte_t* name;
            const int32_t nameLength;
            void (*commandFunction)();
        };

        static const struct Command commands[COMMANDS_COUNT];

        static byte_t inputBuffer[INPUT_BUFFER_SIZE];
        static int32_t inputLength;

        static void commandHandler();
        static void clearInputBuffer();
        static void helloCommand();
    };
}

#endif