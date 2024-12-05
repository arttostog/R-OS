#include <./utils/ros_uart_logger.h>

using namespace ROS;

void* Logger::clock = nullptr;
bool Logger::isLogging = false;

void Logger::log(IN LogType logType, IN const char* string) {
    log(logType, string, String::getStringSize(string));
}

void Logger::log(IN LogType logType, IN const char* string, IN uint32_t stringSize) {
    while (isLogging)
        continue;

    isLogging = true;

    if (clock != nullptr) {
        Output::putByte('(');
        char buffer[20];
        String::numberToString(((Clock*) clock)->getUptime(), buffer, 20, true);
        Output::putBytes(buffer, 20);
        Output::putBytes(") ", 2);
    }

    Output::putBytes("{core-", 6);
    char buffer[2];
    String::numberToString(get_current_core(), buffer, 2, true);
    Output::putBytes(buffer, 2);
    Output::putBytes("} ", 2);

    Output::putByte('[');
    const char* convertedLogType = convertLogTypeToString(logType);
    Output::putBytes(convertedLogType, String::getStringSize(convertedLogType));
    Output::putBytes("] : ", 4);

    Output::putBytes(string, stringSize);
    Output::putByte('\n');

    isLogging = false;
}

const char* Logger::convertLogTypeToString(IN LogType logType) {
    switch (logType)
    {
        case INFO:
            return "INFO";
        case WARN:
            return "WARN";
        case ERROR:
            return "ERROR";
        default:
            return "UNDEFINED";
    }
}