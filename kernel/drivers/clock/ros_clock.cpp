#include <./drivers/clock/ros_clock.h>

using namespace ROS;

Clock::Clock() {
    clockFrequency = clock_frequency();

    if (clockFrequency < 1 * MHZ || clockFrequency > 500 * MHZ)
        Output::putBytes("Readed invalid clock frequency!", 31);
}

uint32_t Clock::getFrequency() {
    return clockFrequency;
}

uint64_t Clock::getUptime() {
    return (clock_uptime() * NANOSECONDS_IN_SECOND) / clockFrequency;
}