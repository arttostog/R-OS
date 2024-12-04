#include <./utils/ros_uart0_logger.h>

using ROS::Logger, ROS::Output, ROS::String, ROS::Clock;

Logger::Logger() {
    this->clock = nullptr;
}

Logger::Logger(IN Clock* clock) {
    this->clock = clock;
}

void Logger::log(IN LogType logType, IN const char* string) {
    logStart(logType);
    Output::putBytes(string, ROS::String::getStringSize(string));
    Output::putByte('\n');
}

void Logger::log(IN LogType logType, IN const char* string, IN uint32_t stringSize) {
    logStart(logType);
    Output::putBytes(string, stringSize);
    Output::putByte('\n');
}

void Logger::logStart(IN LogType logType) {
    if (clock != nullptr) {
        Output::putByte('(');
        char buffer[20];
        String::numberToString(clock->getUptime(), buffer, 20, true);
        Output::putBytes(buffer, 20);
        Output::putBytes(") ", 2);
    }

    Output::putByte('[');
    const char* convertedLogType = convertLogTypeToString(logType);
    Output::putBytes(convertedLogType, String::getStringSize(convertedLogType));
    Output::putBytes("] : ", 4);
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