#include <./drivers/ros_lfb.h>

using ROS::Lfb, ROS::MailBox, ROS::Logger;

Lfb::Screen Lfb::screen = { };
void* Lfb::lfb = nullptr;

void Lfb::init() {
    MailBox::mailbox[0] = 35 * 4;
    MailBox::mailbox[1] = MailBox::MAILBOX_REQUEST;
    MailBox::mailbox[2] = 0x48003;
    MailBox::mailbox[3] = 8;
    MailBox::mailbox[4] = 8;
    MailBox::mailbox[5] = 640;
    MailBox::mailbox[6] = 320;
    MailBox::mailbox[7] = 0x48004;
    MailBox::mailbox[8] = 8;
    MailBox::mailbox[9] = 8;
    MailBox::mailbox[10] = 640;
    MailBox::mailbox[11] = 320;
    MailBox::mailbox[12] = 0x48009;
    MailBox::mailbox[13] = 8;
    MailBox::mailbox[14] = 8;
    MailBox::mailbox[15] = 0;
    MailBox::mailbox[16] = 0;
    MailBox::mailbox[17] = 0x48005;
    MailBox::mailbox[18] = 4;
    MailBox::mailbox[19] = 4;
    MailBox::mailbox[20] = 32;
    MailBox::mailbox[21] = 0x48006;
    MailBox::mailbox[22] = 4;
    MailBox::mailbox[23] = 4;
    MailBox::mailbox[24] = 1;
    MailBox::mailbox[25] = 0x40001;
    MailBox::mailbox[26] = 8;
    MailBox::mailbox[27] = 8;
    MailBox::mailbox[28] = 4096;
    MailBox::mailbox[29] = 0;
    MailBox::mailbox[30] = 0x40008;
    MailBox::mailbox[31] = 4;
    MailBox::mailbox[32] = 4;
    MailBox::mailbox[33] = 0;
    MailBox::mailbox[34] = MailBox::MAILBOX_TAG_LAST;

    if (MailBox::call(MailBox::MAILBOX_CHANNEL_PROP) && MailBox::mailbox[20] == 32 && MailBox::mailbox[28] != 0) {
        MailBox::mailbox[28] &= 0x3FFFFFFF;
        screen.width = MailBox::mailbox[5];
        screen.height = MailBox::mailbox[6];
        screen.pitch = MailBox::mailbox[33];
        screen.isRgb = MailBox::mailbox[24];
        lfb = (void*) ((uint64_t) MailBox::mailbox[28]);
        return;
    }
    Logger::log(Logger::ERROR, "Unable to set screen settings!");
}

void Lfb::show(IN const Image* imageToShow) {
    uint32_t* image = imageToShow->image;
    int32_t imageWidth = imageToShow->imageWidth,
        imageHeight = imageToShow->imageHeight;

    byte_t *pointer = (byte_t*) ((uint64_t) lfb + imageToShow->imageStartPixelPosition);

    for (int32_t y = 0; y < imageHeight; pointer += imageToShow->imageNewLine, ++y)
        for (int32_t x = 0; x < imageWidth; ++image, pointer += 4, ++x)
            *((uint32_t*) pointer) = convertColor(*image);
}

void Lfb::clearScreen() {
    fillScreen(0x000000FF);
}

void Lfb::fillScreen(IN uint32_t color) {
    for (uint32_t y = 0, lfbIndex = 0; y < screen.height; ++y)
        for (uint32_t x = 0; x < screen.width; ++lfbIndex, ++x) {
            ((uint32_t*) lfb)[lfbIndex] = convertColor(color);
        }
}

const Lfb::Screen* Lfb::getScreen() {
    return &screen;
}

uint32_t Lfb::convertColor(IN uint32_t color) {
    byte_t* oldColor = ((byte_t*) &color);
    return (uint32_t) oldColor[3] + (screen.isRgb ? ((uint32_t) oldColor[0] << 24) + ((uint32_t) oldColor[1] << 16) + ((uint32_t) oldColor[2] << 8) : (uint32_t) oldColor[3] + ((uint32_t) oldColor[2] << 24) + ((uint32_t) oldColor[1] << 16) + ((uint32_t) oldColor[0] << 8));
}