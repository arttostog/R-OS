#include <./drivers/ros_clock.hpp>

ROS::Clock::Clock(void) {
    clockFrequency = clock_frequency();

    if (clockFrequency < 1 * MHZ || clockFrequency > 500 * MHZ)
        ROS::Logger::log(ROS::Logger::ERROR, "Readed invalid clock frequency!");
}

u32_t ROS::Clock::getFrequency(void) {
    return clockFrequency;
}

u64_t ROS::Clock::getUptime(void) {
    return (clock_uptime() * NANOSECONDS_IN_SECOND) / clockFrequency;
}