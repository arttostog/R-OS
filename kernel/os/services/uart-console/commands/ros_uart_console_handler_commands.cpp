#include <./os/services/uart-console/commands/ros_uart_console_handler_commands.h>

using namespace ROS;

const struct UartConsoleHandlerCommands::Command UartConsoleHandlerCommands::commands[UartConsoleHandlerCommands::COMMANDS_COUNT] = {
    { "hello", 5, UartConsoleHandlerCommands::helloCommand, true },
    { "testWait", 8, UartConsoleHandlerCommands::testWaitCommand, false},
    { "shutdown", 8, Power::shutdown, true }
};

void UartConsoleHandlerCommands::helloCommand() {
    Logger::log(Logger::INFO, "Hello!");
}

void UartConsoleHandlerCommands::testWaitCommand() {
    Clock::delay(5.0f);
}