#include <./utils/ros_logger.h>

using ROS::Logger, ROS::Output, ROS::String;

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