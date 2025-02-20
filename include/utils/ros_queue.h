#ifndef ROS_QUEUE_H
#define ROS_QUEUE_H

#include <ros_standart.h>
#include <./drivers/ros_cores.h>
#include <./drivers/ros_task_manager.h>
#include <./drivers/ros_clock.h>

namespace ROS {
    class Queue {
        public:
            Queue();

            uint64_t getInLine();
            void wait(uint64_t uniqueTaskId);
            void stepOutOfLine();
        private:
            static constexpr int32_t QUEUE_MAX_LENGTH = (TaskManager::CORES_FOR_TASKS + 1) * 5;
            uint64_t queue[QUEUE_MAX_LENGTH];
            int32_t queueLength;
    };
}

#endif