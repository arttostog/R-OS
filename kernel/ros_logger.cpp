#include <ros_logger.hpp>

void ROS::Logger::log(IN LogType type, IN const char* message) {
    ROS::Output::putByte('[');
    ROS::Output::putBytes(convertLogTypeToString(type));
    ROS::Output::putBytes("] : ");
    ROS::Output::putBytes(message);
    ROS::Output::putByte('\n');
}

const char* ROS::Logger::convertLogTypeToString(IN LogType type) {
    switch (type)
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