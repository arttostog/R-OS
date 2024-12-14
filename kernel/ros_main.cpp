#include <./utils/logger/ros_uart_logger.h>
#include <./drivers/power/ros_power.h>
#include <./drivers/clock/ros_clock.h>
#include <./utils/string/ros_string.h>
#include <./drivers/uart/ros_uart_input.h>
#include <./drivers/task-manager/ros_task_manager.h>
#include <./drivers/mailbox/ros_mailbox.h>
#include <./drivers/lfb/ros_lfb.h>
#include <./utils/image-painter/ros_image_painter.h>
#include <./utils/color/ros_color.h>
#include <./utils/font/ros_font_s.h>
#include <./utils/font/ros_font.h>

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
    { "reset", 5, Power::softReset }
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

void mailboxTestCall() {
    MailBox::mailbox[0] = 8 * 4;
    MailBox::mailbox[1] = MailBox::MAILBOX_REQUEST;
    MailBox::mailbox[2] = MailBox::MAILBOX_TAG_GETSERIAL;
    MailBox::mailbox[3] = 8;
    MailBox::mailbox[4] = 8;
    MailBox::mailbox[5] = 0;
    MailBox::mailbox[6] = 0;
    MailBox::mailbox[7] = MailBox::MAILBOX_TAG_LAST;

    if (MailBox::call(MailBox::MAILBOX_CHANNEL_PROP)) {
        char buffer[10];
        String::numberToString(MailBox::mailbox[6], buffer, 10, false);
        Logger::log(Logger::INFO, buffer, 10);
        String::numberToString(MailBox::mailbox[5], buffer, 10, false);
        Logger::log(Logger::INFO, buffer, 10);
        return;
    }
    Logger::log(Logger::ERROR, "Failed to get serial number!");
}

Clock clock;

extern "C" {
    void kernel_main() {
        clock = Clock();
        Uart::init();
        Logger::setClock(&clock);

        Lfb lfb(&clock);
        Lfb::Screen screen = lfb.getScreen();

        uint32_t imageData[102400] = { };
        struct Image image = {
            imageData, 320, 320, (screen.height - 320) / 2 * screen.pitch + (screen.width - 320) * 2, screen.pitch - 320 * 4
        };
        ImagePainter::drawPixels(&image, 0, 102400 - 1, Color::LIGHT_RED);
        lfb.show(&image);

        uint32_t imageData2[4096] = { };
        image = {
            imageData2, 64, 64, 32, screen.pitch - 64 * 4
        };
        ImagePainter::drawPixels(&image, 0, 4096 - 1, Color::BLUE);

        lfb.show(&image);

        Image xImage = {
            nullptr, 0, 0, 0, 0 
        };
        Font::getSymbolAsImage(&xImage, '5');
        xImage.imageNewLine = screen.pitch - xImage.imageWidth * 4;

        lfb.show(&xImage);

        Logger::log(Logger::INFO, "Hello World!");

        TaskManager::addTask(testTask);

        Logger::log(Logger::INFO, font_pointer, 2);

        mailboxTestCall();

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