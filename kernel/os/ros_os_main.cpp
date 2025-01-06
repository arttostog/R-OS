#include <./os/ros_os_main.h>

using namespace ROS;

void OsMain::start() {
    Logo logo(Lfb::getScreen());
    logo.showLogo();

    UartConsoleHandler::init();
}

void OsMain::loop() {
    UartConsoleHandler::handle();
}