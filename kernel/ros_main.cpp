#include <./utils/ros_uart_logger.h>
#include <ros_system_s.h>
#include <./drivers/clock/ros_clock.h>
#include <./utils/ros_string.h>
#include <./uart/ros_uart_input.h>
#include <./uart/ros_uart_output.h>

using namespace ROS;

Clock clock;
Logger logger;

#define INPUT_BUFFER_SIZE 64

byte_t inputBuffer[INPUT_BUFFER_SIZE];
int32_t inputBufferLength = 0;

struct Command
{
    const byte_t* name;
    const int32_t nameLength;
    void (*commandFunction)();
};

void helloCommand() {
    logger.log(Logger::INFO, "Hello!");
}

#define COMMANDS_COUNT 2

struct Command commands[COMMANDS_COUNT] = {
    { "hello", 5, helloCommand},
    { "shutdown", 8, shutdown }
};

bool equal(const byte_t* firstBuffer, const byte_t* secondBuffer, int32_t buffersSize) {
    for (int32_t i = 0; i < buffersSize; ++i)
        if (firstBuffer[i] != secondBuffer[i])
            return false;
    return true;
}

void commandHandler(const byte_t* buffer, int32_t bufferSize) {
    for (int32_t i = 0, nameLength; i < COMMANDS_COUNT; ++i)
        if (bufferSize == commands[i].nameLength)
            if (equal(buffer, commands[i].name, bufferSize)) {
                commands[i].commandFunction();
                break;
            }
}

void clearInputBuffer(byte_t* inputBuffer, int32_t* inputBufferLength) {
    for (int32_t i = 0; i <= *inputBufferLength; ++i)
        inputBuffer[i] = '\0';
    *inputBufferLength = 0;
}

extern "C" {
    void kernel_main() {
        clock = Clock();
        logger = Logger(&clock);

        logger.log(Logger::INFO, "Hello World!");

        logger.log(Logger::INFO, "Test 1");
        logger.log(Logger::WARN, "Test 2");
        logger.log(Logger::ERROR, "Test 3");
        logger.log((Logger::LogType) 3, "Test 4");
        Output::putBytes("> ", 2);
    }

    void kernel_loop() {
        byte_t byte = Input::getByte();

        if (byte == '\r') {
            Output::putByte('\n');
            commandHandler(inputBuffer, inputBufferLength);
            clearInputBuffer(inputBuffer, &inputBufferLength);
            Output::putBytes("> ", 3);
            return;
        }

        if (inputBufferLength < INPUT_BUFFER_SIZE) {
            Output::putByte(byte);
            inputBuffer[inputBufferLength] = byte;
            ++inputBufferLength;
        }
    }
}