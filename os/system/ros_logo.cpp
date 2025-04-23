#include "ros_logo.h"

using ROS_OS::Logo, ROS::Lfb, ROS::ImageFromBmp;

Logo::Logo(const Lfb::Screen* screen) {
    logoImage = {
        logoBuffer,
        LOGO_WIDTH,
        LOGO_HEIGHT,
        (screen->height - LOGO_WIDTH) / 2 * screen->pitch + (screen->width - LOGO_WIDTH) * 2,
        screen->pitch - LOGO_WIDTH * 4
    };

    ImageFromBmp::get(&logoImage, logo_pointer, logoImage.imageWidth * (logoImage.imageHeight - 1), logoImage.imageWidth);
}

void Logo::show() {
    Lfb::clearScreen();
    Lfb::show(&logoImage);
}