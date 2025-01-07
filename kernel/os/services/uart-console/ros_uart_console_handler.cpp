#include <./os/services/uart-console/ros_uart_console_handler.h>

using namespace ROS;

const struct UartConsoleHandler::Command UartConsoleHandler::commands[UartConsoleHandler::COMMANDS_COUNT] = {
    { "hello", 5, UartConsoleHandler::helloCommand },
    { "shutdown", 8, Power::shutdown }
};

byte_t UartConsoleHandler::inputBuffer[INPUT_BUFFER_SIZE] = { };
int32_t UartConsoleHandler::inputLength = 0;

void UartConsoleHandler::init() {
    Logger::log(Logger::INFO, "Hello from R-OS!");
    UartOutput::putBytes("> ", 2);
}

void UartConsoleHandler::commandHandler() {
    for (int32_t i = 0; i < COMMANDS_COUNT; ++i)
        if (inputLength == commands[i].nameLength)
            if (String::checkIfStringsAreEqual(inputBuffer, commands[i].name, inputLength)) {
                TaskManager::addTask(commands[i].commandFunction);
                break;
            }
}

void UartConsoleHandler::clearInputBuffer() {
    for (int32_t i = 0; i <= inputLength; ++i)
        inputBuffer[i] = '\0';
    inputLength = 0;
}

void UartConsoleHandler::handle() {
    byte_t byte = UartInput::getByte();

    if (byte == '\r') {
        UartOutput::putByte('\n');
        commandHandler();
        clearInputBuffer();
        UartOutput::putBytes("> ", 3);
        return;
    }

    if (inputLength < INPUT_BUFFER_SIZE) {
        UartOutput::putByte(byte);
        inputBuffer[inputLength] = byte;
        ++inputLength;
    }
}

void UartConsoleHandler::helloCommand() {
    Logger::log(Logger::INFO, "Hello!");
}