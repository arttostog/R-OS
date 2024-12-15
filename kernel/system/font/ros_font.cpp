#include <./system/font/ros_font.h>

using namespace ROS;

const uint32_t* Font::symbolPointer = (uint32_t*) (((uint64_t) font_pointer) + 0x8A);
uint32_t Font::symbolImage[FONT_SYMBOL_HEIGHT * FONT_SYMBOL_WIDTH] = { };

void Font::getSymbolAsImage(IN Lfb::Image* image, IN char symbol) {
    image->imageWidth = FONT_SYMBOL_WIDTH;
    image->imageHeight = FONT_SYMBOL_HEIGHT;
    
    uint32_t symbolPointerIndex = symbol * FONT_SYMBOL_WIDTH + NEW_LINE_MARGIN * (FONT_SYMBOL_HEIGHT - 1);
    
    for (uint32_t y = 0, symbolImageIndex = 0; y < FONT_SYMBOL_HEIGHT; symbolPointerIndex -= NEW_LINE_MARGIN + FONT_SYMBOL_WIDTH, ++y)
        for (uint32_t x = 0; x < FONT_SYMBOL_WIDTH; ++symbolPointerIndex, ++symbolImageIndex, ++x) {
            byte_t* pixel = ((byte_t*) &symbolPointer[symbolPointerIndex]);
            symbolImage[symbolImageIndex] = ((uint32_t) pixel[3]) + ((uint32_t) pixel[2] << 24) + ((uint32_t) pixel[1] << 16) + ((uint32_t) pixel[0] << 8);
        }

    image->image = symbolImage;
}