#include <./drivers/clock/ros_clock.h>

ROS::Clock::Clock(void) {
    clockFrequency = clock_frequency();

    if (clockFrequency < 1 * MHZ || clockFrequency > 500 * MHZ)
        ROS::Logger::log(ROS::Logger::ERROR, "Readed invalid clock frequency!");
}

uint32_t ROS::Clock::getFrequency(void) {
    return clockFrequency;
}

uint64_t ROS::Clock::getUptime(void) {
    return (clock_uptime() * NANOSECONDS_IN_SECOND) / clockFrequency;
}