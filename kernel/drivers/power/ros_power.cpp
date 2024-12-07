#include <./drivers/power/ros_power.h>

using namespace ROS;

void Power::shutdown() {
    for (uint32_t i = 0; i < TaskManager::coresForTasks; ++i)
        TaskManager::tasks[i] = halt;
    halt();
}

void Power::softReset() {
    _start();
}