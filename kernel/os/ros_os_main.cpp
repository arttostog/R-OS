#include <./os/ros_os_main.h>

using namespace ROS;

void OsMain::start() {
    Logo logo(Lfb::getScreen());
    logo.showLogo();

    ConsoleHandler::init();
    UartConsoleHandler::init();
}

void OsMain::loop() {
    ConsoleHandler::handle();
    UartConsoleHandler::handle();
}