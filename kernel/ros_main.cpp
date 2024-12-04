#include <ros_output.hpp>
#include <./utils/ros_logger.hpp>
#include <ros_system.hpp>
#include <./drivers/clock/ros_clock.hpp>
#include <./utils/ros_converter.hpp>

using ROS::Clock, ROS::Logger, ROS::Converter;

extern "C" {
    void kernel_main(void) {
        char buffer[4];
        Converter::numberToString(100, buffer, 3);

        Logger::log(Logger::INFO, "Hello World!");
        Logger::log(Logger::INFO, buffer);
        shutdown();
    }

    void kernel_loop(void) {
        
    }
}