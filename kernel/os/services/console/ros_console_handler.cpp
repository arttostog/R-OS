#include <./os/services/console/ros_console_handler.h>

using namespace ROS;

uint32_t ConsoleHandler::symbolBuffer[Font::FONT_SYMBOL_SIZE];
Lfb::Image ConsoleHandler::symbolImage = { };
Logo ConsoleHandler::logo = nullptr;

void ConsoleHandler::init() {
    const Lfb::Screen* screen = Lfb::getScreen();

    logo = Logo(screen);

    Font::getSymbolAsImage(&symbolImage, symbolBuffer, '_');
    symbolImage.imageStartPixelPosition = 0;
    symbolImage.imageNewLine = screen->pitch - Font::FONT_SYMBOL_WIDTH * 4;

    TaskManager::addTask(handle);
}

void ConsoleHandler::handle() {
    Lfb::clearScreen();
    
    logo.show();

    Clock::delay(2.5f);
    Lfb::clearScreen();

    while (true) {
        Lfb::show(&symbolImage);
        Clock::delay(1.0f);
        Lfb::clearScreen();
        Clock::delay(1.0f);
    }
}