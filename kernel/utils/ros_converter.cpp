#include <./utils/ros_converter.hpp>

void ROS::Converter::numberToString(IN uint64_t number, OUT char* buffer, IN int32_t bufferSize) {
    for (int32_t i = bufferSize - 1; i >= 0; buffer[i] = (number % 10) + '0', number /= 10, --i);
}