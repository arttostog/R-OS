#ifndef ROS_VIRTIO_GPU_PCI_H
#define ROS_VIRTIO_GPU_PCI_H

#include <ros_standart.h>

#define GPU ((byte_t*) 0xC0000000)

namespace ROS {
    class VirtioGpuPci {
    public:
        static void putByte(IN byte_t byte);
        static void putBytes(IN const byte_t* bytes, IN uint32_t bytesCount);
    };
}

#endif