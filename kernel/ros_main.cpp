#include <ros_output.hpp>
#include <./utils/ros_logger.hpp>
#include <ros_system.hpp>
#include <./drivers/clock/ros_clock.hpp>
#include <./utils/ros_string.hpp>

using ROS::Clock, ROS::Logger, ROS::String;

extern "C" {
    Clock clock;
    uint64_t loopCounter = 0;

    void kernel_main(void) {
        clock = Clock();
        Logger::log(Logger::INFO, "Hello World!");
    }

    void kernel_loop(void) {
        char buffer[20];
        String::numberToString(clock.getUptime(), buffer, 20);
        Logger::log(Logger::INFO, buffer, 20);

        if (++loopCounter == 10)
            shutdown();
    }
}