#include <./system/logger/ros_uart_logger.h>
#include <./system/power/ros_power.h>
#include <./drivers/clock/ros_clock.h>
#include <./drivers/uart/ros_uart_input.h>
#include <./system/task-manager/ros_task_manager.h>
#include <./drivers/lfb/ros_lfb.h>
#include <./system/font/ros_font.h>
#include <./utils/image-from-bmp/ros_image_from_bmp.h>
#include <./system/logo/ros_logo.h>

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
    { "hello", 5, helloCommand },
    { "shutdown", 8, Power::shutdown }
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

void coresTestTask() {
    Logger::log(Logger::SUCCESS, "Cores -> working!");
}

Lfb lfb;

extern "C" {
    void kernel_main() {
        Clock::init();
        Uart::init();

        Logger::log(Logger::INFO, "Hello from R-OS!");

        lfb = Lfb();
        Lfb::Screen screen = lfb.getScreen();

        uint32_t logoBuffer[Logo::LOGO_WIDTH * Logo::LOGO_HEIGHT];
        Lfb::Image logoImage = {
            logoBuffer, Logo::LOGO_WIDTH, Logo::LOGO_HEIGHT, (screen.height - Logo::LOGO_WIDTH) / 2 * screen.pitch + (screen.width - Logo::LOGO_WIDTH) * 2, screen.pitch - logoImage.imageWidth * 4
        };

        ImageFromBmp::get(&logoImage, logo_pointer, logoImage.imageWidth * (logoImage.imageHeight - 1), logoImage.imageWidth);

        lfb.show(&logoImage);

        TaskManager::addTask(coresTestTask);

        Logger::log(Logger::SUCCESS, "System started successfully!");
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