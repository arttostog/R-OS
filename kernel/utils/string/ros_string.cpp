#include <./kernel/utils/string/ros_string.h>

using namespace ROS;

bool String::checkIfStringsAreEqual(const byte_t* firstString, const byte_t* secondString, int32_t stringsSize) {
    for (int32_t i = 0; i < stringsSize; ++i)
        if (firstString[i] != secondString[i])
            return false;
    return true;
}

void String::numberToString(IN uint64_t number, OUT char* buffer, IN int32_t bufferSize, IN bool cleanFirstZeros) {
    for (int32_t i = bufferSize - 1; i >= 0; buffer[i] = (number % 10) + '0', number /= 10, --i);
    if (cleanFirstZeros)
        for (int32_t i = 0; i < bufferSize - 1 && buffer[i] == '0'; buffer[i] = '\0', ++i);
}

uint32_t String::getStringSize(IN const char* string) {
    uint32_t stringSize = 0;
    for (; string[stringSize] != '\0'; ++stringSize);
    return stringSize;
}