#include <./utils/logger/ros_uart_logger.h>

using namespace ROS;

void Logger::log(IN LogType logType, IN uint64_t number) {
    char buffer[20];
    String::numberToString(number, buffer, 20, true);
    log(logType, buffer, 20);
}

void Logger::log(IN LogType logType, IN const char* string) {
    log(logType, string, String::getStringSize(string));
}

void Logger::log(IN LogType logType, IN const char* string, IN uint32_t stringSize) {
    StringBuilder builder;

    builder.append('(');
    char buffer[20];
    String::numberToString(Clock::getUptime(), buffer, 20, true);
    builder.append(buffer, 20);
    builder.append(") ", 2);

    builder.append("{core-", 6);
    char coreBuffer[2];
    String::numberToString(get_current_core(), coreBuffer, 2, true);
    builder.append(coreBuffer, 2);
    builder.append("} ", 2);

    builder.append('[');
    builder.append(logType);
    builder.append("] : ", 4);

    builder.append(string, stringSize);
    builder.append('\n');

    UartOutput::putBytes(builder.string, builder.stringLength);
}