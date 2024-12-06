#include <./drivers/power/ros_power.h>

using namespace ROS;

void Power::shutdown() {
    for (int32_t i = 0; i < CORES_FOR_TASKS; ++i)
        tasks[i] = halt;
    halt();
}

void Power::softReset() {
    _start();
}