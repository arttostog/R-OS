#include "ros_uart_console_handler.h"

using namespace ROS;

byte_t UartConsoleHandler::inputBuffer[INPUT_BUFFER_SIZE] = { };
uint32_t UartConsoleHandler::inputLength = 0;

void UartConsoleHandler::init() {
    Logger::log(Logger::INFO, "Hello from R-OS!");
    UartOutput::putBytes("> ", 2);
}

void UartConsoleHandler::commandHandler() {
    for (uint32_t i = 0; i < UartConsoleHandlerCommands::COMMANDS_COUNT; ++i) {
        UartConsoleHandlerCommands::Command command = UartConsoleHandlerCommands::commands[i];
        if (inputLength == command.nameLength)
            if (String::checkIfStringsAreEqual(inputBuffer, command.name, inputLength)) {
                TaskManager::pptr* addedTask = TaskManager::addTask(command.commandFunction);
                if (command.await)
                    TaskManager::awaitAddedTask(addedTask);
                return;
            }
    }
}

void UartConsoleHandler::clearInputBuffer() {
    for (uint32_t i = 0; i <= inputLength; ++i)
        inputBuffer[i] = '\0';
    inputLength = 0;
}

void UartConsoleHandler::handle() {
    byte_t byte = UartInput::getByte();

    if (!byte)
        return;

    if (byte == '\r') {
        UartOutput::putBytes("\n", 1);
        commandHandler();
        clearInputBuffer();
        UartOutput::putBytes("> ", 3);
        return;
    }

    if (inputLength < INPUT_BUFFER_SIZE) {
        UartOutput::putBytes(&byte, 1);
        inputBuffer[inputLength] = byte;
        ++inputLength;
    }
}