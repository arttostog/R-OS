#include <./utils/image-from-bmp/ros_image_from_bmp.h>

using namespace ROS;

void ImageFromBmp::get(OUT Lfb::Image* image, IN const void* bmp, IN uint32_t bmpStartIndex, IN uint32_t newLineMargin) {
    uint32_t* bmpPixels = (uint32_t*) (((uint64_t) bmp) + 0x8A);

    for (uint32_t y = 0, symbolImageIndex = 0; y < image->imageHeight; bmpStartIndex -= newLineMargin + image->imageWidth, ++y)
        for (uint32_t x = 0; x < image->imageWidth; ++bmpStartIndex, ++symbolImageIndex, ++x) {
            byte_t* pixel = (byte_t*) &bmpPixels[bmpStartIndex];
            image->image[symbolImageIndex] = (uint32_t) pixel[3] + ((uint32_t) pixel[2] << 24) + ((uint32_t) pixel[1] << 16) + ((uint32_t) pixel[0] << 8);
        }
}