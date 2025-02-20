#include <./utils/ros_queue.h>

using namespace ROS;

Queue::Queue() {
    this->queueLength = 0;
}

uint64_t Queue::getInLine() {
    uint64_t uniqueTaskId = Clock::getUptime();
    queue[this->queueLength] = uniqueTaskId;
    ++this->queueLength;
    return uniqueTaskId;
}

void Queue::wait(uint64_t uniqueTaskId) {
    while (queue[0] != uniqueTaskId)
        continue;
}

void Queue::stepOutOfLine() {
    for (int32_t i = 1; i < this->queueLength; ++i)
        queue[i - 1] = queue[i];
    queue[this->queueLength - 1] = 0;
    --this->queueLength;
}