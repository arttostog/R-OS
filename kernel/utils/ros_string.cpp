#include <./utils/ros_string.hpp>

using ROS::String;

void String::numberToString(IN uint64_t number, OUT char* buffer, IN int32_t bufferSize) {
    for (int32_t i = bufferSize - 1; i >= 0; buffer[i] = (number % 10) + '0', number /= 10, --i);
}

uint32_t String::getStringSize(IN const char* string) {
    uint32_t stringSize = 0;
    for (; string[stringSize] != '\0'; ++stringSize);
    return stringSize;
}