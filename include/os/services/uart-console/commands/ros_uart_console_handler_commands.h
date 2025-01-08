#ifndef ROS_UART_CONSOLE_HANDLER_COMMANDS_H
#define ROS_UART_CONSOLE_HANDLER_COMMANDS_H

#include <ros_standart.h>
#include <./utils/logger/ros_uart_logger.h>
#include <./drivers/clock/ros_clock.h>
#include <./drivers/power/ros_power.h>
#include <./drivers/task-manager/ros_task_manager.h>
#include <./utils/string/ros_string_builder.h>
#include <./utils/string/ros_string.h>

namespace ROS {
    class UartConsoleHandlerCommands {
    public:
        struct Command {
            const char* name;
            uint32_t nameLength;
            const char* description;
            uint32_t descriptionLength;
            void (*commandFunction)();
            bool await;
        };

        static constexpr uint32_t COMMANDS_COUNT = 4;
        static const struct Command commands[COMMANDS_COUNT];
    private:
        static StringBuilder builder;

        static void helpCommand();
        static void helloCommand();
        static void coresInWorkCommand();
    };
}

#endif