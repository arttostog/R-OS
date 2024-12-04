#include <./utils/ros_uart0_logger.h>
#include <ros_system_s.h>
#include <./drivers/clock/ros_clock.h>
#include <./utils/ros_string.h>

using ROS::Clock, ROS::Logger, ROS::String;

Clock clock;
Logger logger;
uint64_t loopCounter = 0;

extern "C" {
    void kernel_main() {
        clock = Clock();
        logger = Logger(&clock);

        logger.log(Logger::INFO, "Hello World!");

        logger.log(Logger::INFO, "Test 1");
        logger.log(Logger::WARN, "Test 2");
        logger.log(Logger::ERROR, "Test 3");
        logger.log((Logger::LogType) 3, "Test 4");

        shutdown();
    }

    void kernel_loop() {}
}