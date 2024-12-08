#include <./drivers/clock/ros_clock.h>

using namespace ROS;

Clock::Clock() {
    clockFrequency = clock_frequency();

    if (clockFrequency < 1 * MHZ || clockFrequency > 500 * MHZ)
        Logger::log(Logger::ERROR, "Readed invalid clock frequency!");
}

uint32_t Clock::getFrequency() {
    return clockFrequency;
}

uint64_t Clock::getUptime() {
    return (uint64_t) (((__uint128_t) clock_uptime()) * NANOSECONDS_IN_SECOND / clockFrequency);
}

void Clock::delay(IN float64_t seconds) {
    uint64_t stop = getUptime() + (uint64_t) (seconds * NANOSECONDS_IN_SECOND);
    while (getUptime() < stop)
        continue;
}

void Clock::delayByCycles(IN uint64_t cycles) {
    while (--cycles)
        continue;
}