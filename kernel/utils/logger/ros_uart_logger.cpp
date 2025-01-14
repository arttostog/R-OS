#include <./kernel/utils/logger/ros_uart_logger.h>

using namespace ROS;

bool Logger::isBusy = false;
StringBuilder Logger::builder = StringBuilder();

void Logger::log(IN LogType logType, IN const char* string) {
    log(logType, string, String::getStringSize(string));
}

void Logger::log(IN LogType logType, IN const char* string, IN uint32_t stringSize) {
    while (isBusy)
        continue;
    
    isBusy = true;

    builder.append('(');
    builder.append(Clock::getUptime());
    builder.append(") ", 2);

    builder.append("{core-", 6);
    builder.append(get_current_core());
    builder.append("} ", 2);

    builder.append('[');
    builder.append(logType);
    builder.append("] : ", 4);

    builder.append(string, stringSize);
    builder.append('\n');

    UartOutput::putBytes(builder.string, builder.stringLength);

    builder.clean();

    isBusy = false;
}