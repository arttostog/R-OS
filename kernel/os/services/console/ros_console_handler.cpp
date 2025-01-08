#include <./os/services/console/ros_console_handler.h>

using namespace ROS;

uint32_t ConsoleHandler::symbolBuffer[Font::FONT_SYMBOL_SIZE];
Lfb::Image ConsoleHandler::symbolImage = { };

void ConsoleHandler::init() {
    const Lfb::Screen* screen = Lfb::getScreen();

    Font::getSymbolAsImage(&symbolImage, symbolBuffer, '_');
    symbolImage.imageStartPixelPosition = 0;
    symbolImage.imageNewLine = screen->pitch - Font::FONT_SYMBOL_WIDTH * 4;

    Logo logo(screen);
    logo.show();

    TaskManager::addTask(handle);
}

void ConsoleHandler::handle() {
    Clock::delay(2.5f);
    Lfb::clearScreen();

    while (true) {
        Lfb::show(&symbolImage);
        Clock::delay(1.0f);
        Lfb::clearScreen();
        Clock::delay(1.0f);
    }
}