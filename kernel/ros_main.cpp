#include <ros_output.hpp>
#include <ros_logger.hpp>
#include <ros_system.hpp>
#include <./drivers/ros_clock.hpp>

extern "C" void kernel_main(void) {
    ROS::Logger::log(ROS::Logger::INFO, "Hello World!");
    shutdown();
}