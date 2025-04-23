#include "ros_uart_console_handler_commands.h"

using ROS_OS::UartConsoleHandlerCommands, ROS::StringBuilder, ROS::Power, ROS::Logger, ROS::TaskManager;

StringBuilder UartConsoleHandlerCommands::builder = StringBuilder();

const struct UartConsoleHandlerCommands::Command UartConsoleHandlerCommands::commands[UartConsoleHandlerCommands::COMMANDS_COUNT] = {
    { "help", 4, "Returns commands list.", 22, UartConsoleHandlerCommands::helpCommand, true },
    { "hello", 5, "Returns \"Hello!\".", 17, UartConsoleHandlerCommands::helloCommand, true },
    { "cores", 5, "Returns active cores.", 21, UartConsoleHandlerCommands::coresInWorkCommand, true},
    { "shutdown", 8, "Shutdown the system.", 20, Power::shutdown, true }
};

void UartConsoleHandlerCommands::helpCommand() {
    builder.append("List of commands:", 17);

    for (uint32_t i = 0; i < COMMANDS_COUNT; ++i) {
        builder.append('\n');

        Command command = commands[i];
        builder.append(command.name, command.nameLength);
        builder.append(" - ", 3);
        builder.append(command.description, command.descriptionLength);
    }

    Logger::log(Logger::INFO, builder.string, builder.stringLength);
    builder.clean();
}

void UartConsoleHandlerCommands::helloCommand() {
    Logger::log(Logger::INFO, "Hello!");
}

void UartConsoleHandlerCommands::coresInWorkCommand() {
    builder.append("Active cores:\n(This OS supports only ", 38);
    builder.append((uint64_t) TaskManager::CORES_FOR_TASKS + 1);
    builder.append(" cores!)\nCore-0", 16);

    for (uint32_t i = 0; i < TaskManager::CORES_FOR_TASKS; ++i)
        if (TaskManager::coresState[i]) {
            builder.append("\nCore-", 6);
            builder.append((uint64_t) i + 1);
        }

    Logger::log(Logger::INFO, builder.string, builder.stringLength);
    builder.clean();
}