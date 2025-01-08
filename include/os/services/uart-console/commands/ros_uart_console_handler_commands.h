#ifndef ROS_UART_CONSOLE_HANDLER_COMMANDS_H
#define ROS_UART_CONSOLE_HANDLER_COMMANDS_H

#include <ros_standart.h>
#include <./utils/logger/ros_uart_logger.h>
#include <./drivers/clock/ros_clock.h>
#include <./drivers/power/ros_power.h>

namespace ROS {
    class UartConsoleHandlerCommands {
    public:
        struct Command {
            const byte_t* name;
            const int32_t nameLength;
            void (*commandFunction)();
            bool await;
        };

        static constexpr int32_t COMMANDS_COUNT = 3;
        static const struct Command commands[COMMANDS_COUNT];
    private:
        static void helloCommand();
        static void testWaitCommand();
    };
}

#endif