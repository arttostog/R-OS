#include <./drivers/clock/ros_clock.h>

using namespace ROS;

Clock::Clock() {
    clockFrequency = clock_frequency();

    if (clockFrequency < 1 * mhz || clockFrequency > 500 * mhz)
        Logger::log(Logger::ERROR, "Readed invalid clock frequency!");
}

uint32_t Clock::getFrequency() {
    return clockFrequency;
}

uint64_t Clock::getUptime() {
    return clock_uptime() * nanosecondsInSecond / clockFrequency;
}

void Clock::delay(IN float64_t seconds) {
    uint64_t stop = getUptime() + (uint64_t) (seconds * nanosecondsInSecond);
    while (getUptime() < stop)
        continue;
}