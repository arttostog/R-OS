#include <./utils/ros_uart_logger.h>
#include <./drivers/power/ros_power.h>
#include <./drivers/clock/ros_clock.h>
#include <./utils/ros_string.h>
#include <./drivers/uart/ros_uart_input.h>
#include <./drivers/task-manager/ros_task_manager.h>

using namespace ROS;

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
    Logger::log(Logger::INFO, "Hello!");
}

#define COMMANDS_COUNT 3

struct Command commands[COMMANDS_COUNT] = {
    { "hello", 5, helloCommand},
    { "shutdown", 8, Power::shutdown },
    { "reboot", 6, Power::softReboot }
};

bool equal(const byte_t* firstBuffer, const byte_t* secondBuffer, int32_t buffersSize) {
    for (int32_t i = 0; i < buffersSize; ++i)
        if (firstBuffer[i] != secondBuffer[i])
            return false;
    return true;
}

void commandHandler(const byte_t* buffer, int32_t bufferSize) {
    for (int32_t i = 0; i < COMMANDS_COUNT; ++i)
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

void testTask() {
    Logger::log(Logger::INFO, "Testificate");
}

Clock clock;

extern "C" {
    void kernel_main() {
        clock = Clock();
        Logger::clock = &clock;

        Logger::log(Logger::INFO, "Hello World!");

        TaskManager::addTask(testTask);

        Logger::log(Logger::INFO, "Test 1");
        Logger::log(Logger::WARN, "Test 2");
        Logger::log(Logger::ERROR, "Test 3");
        Logger::log((Logger::LogType) 3, "Test 4");
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