#include <./utils/string/ros_string_builder.h>

using namespace ROS;

StringBuilder::StringBuilder() {
    stringLength = 0;
}

void StringBuilder::append(IN const char* string) {
    append(string, String::getStringSize(string));
}

void StringBuilder::append(IN char symbol) {
    if (stringLength >= MAX_STRING_LENGTH)
        return;

    string[stringLength] = symbol;
    ++stringLength;
}

void StringBuilder::append(IN const char* string, IN uint32_t stringLength) {
    for (uint32_t i = 0; i < stringLength; ++this->stringLength, ++i) {
        if (this->stringLength >= MAX_STRING_LENGTH)
            break;
        this->string[this->stringLength] = string[i];
    }
}