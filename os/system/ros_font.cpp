#include "ros_font.h"

using namespace ROS;

void Font::getSymbolAsImage(OUT Lfb::Image* image, OUT uint32_t symbolBuffer[FONT_SYMBOL_SIZE], IN char symbol) {
    image->imageWidth = FONT_SYMBOL_WIDTH;
    image->imageHeight = FONT_SYMBOL_HEIGHT;
    
    image->image = symbolBuffer;

    ImageFromBmp::get(image, font_pointer, symbol * FONT_SYMBOL_WIDTH + NEW_LINE_MARGIN * (FONT_SYMBOL_HEIGHT - 1), NEW_LINE_MARGIN);
}