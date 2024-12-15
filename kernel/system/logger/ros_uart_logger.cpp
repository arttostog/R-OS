#include <./system/logger/ros_uart_logger.h>

using namespace ROS;

Clock* Logger::clock = nullptr;
bool Logger::isLogging = false;

void Logger::setClock(Clock* newClock) {
    clock = newClock;
}

void Logger::log(IN LogType logType, IN const char* string) {
    log(logType, string, String::getStringSize(string));
}

void Logger::log(IN LogType logType, IN const char* string, IN uint32_t stringSize) {
    while (isLogging)
        continue;

    isLogging = true;

    StringBuilder builder;

    if (clock != nullptr) {
        builder.append('(');
        char buffer[20];
        String::numberToString(clock->getUptime(), buffer, 20, true);
        builder.append(buffer, 20);
        builder.append(") ", 2);
    }

    builder.append("{core-", 6);
    char buffer[2];
    String::numberToString(get_current_core(), buffer, 2, true);
    builder.append(buffer, 2);
    builder.append("} ", 2);

    builder.append('[');
    builder.append(logType);
    builder.append("] : ", 4);

    builder.append(string, stringSize);
    builder.append('\n');

    Output::putBytes(builder.string, builder.stringLength);

    isLogging = false;
}