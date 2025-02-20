#include <./utils/ros_image_painter.h>

using namespace ROS;

void ImagePainter::drawPixel(OUT Lfb::Image* image, IN uint32_t pixelPosition, IN uint32_t color) {
    if (pixelPosition >= image->imageWidth * image->imageHeight)
        return;
    image->image[pixelPosition] = color;
}

void ImagePainter::drawPixels(OUT Lfb::Image* image, IN uint32_t startPixelPosition, IN uint32_t endPixelPosition, IN uint32_t color) {
    if (startPixelPosition > endPixelPosition
        || startPixelPosition >= image->imageWidth * image->imageHeight
        || endPixelPosition >= image->imageWidth * image->imageHeight)
        return;

    for (; startPixelPosition <= endPixelPosition; ++startPixelPosition)
        image->image[startPixelPosition] = color;
}