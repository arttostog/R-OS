#include <ros_output.h>
#include <./utils/ros_logger.h>
#include <ros_system_s.h>
#include <./drivers/clock/ros_clock.h>
#include <./utils/ros_string.h>

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
        String::numberToString(clock.getUptime(), buffer, 20, true);
        Logger::log(Logger::INFO, buffer, 20);

        if (++loopCounter == 15)
            shutdown();
    }
}