#ifndef ROS_MAILBOX_H
#define ROS_MAILBOX_H

#include <ros_standart.h>
#include <./drivers/gpio/ros_gpio.h>

namespace ROS {
    class MailBox {
    public:
        static volatile uint32_t mailbox[36];
        
        static const uint64_t MAILBOX_REQUEST = 0,
            MAILBOX_TAG_GETSERIAL = 0x10004,
            MAILBOX_TAG_LAST = 0;

        enum : byte_t {
            MAILBOX_CHANNEL_POWER,
            MAILBOX_CHANNEL_FB,
            MAILBOX_CHANNEL_VUART,
            MAILBOX_CHANNEL_VCHIQ,
            MAILBOX_CHANNEL_LEDS,
            MAILBOX_CHANNEL_BTNS,
            MAILBOX_CHANNEL_TOUCH,
            MAILBOX_CHANNEL_COUNT,
            MAILBOX_CHANNEL_PROP
        };
        
        static bool call(byte_t channel);
    private:
        static const uint64_t VIDEOCORE_MAILBOX = Gpio::MMIO_BASE + 0x0000B880;
        enum : uint64_t {
            MAILBOX_READ = VIDEOCORE_MAILBOX + 0x0,
            MAILBOX_POLL = VIDEOCORE_MAILBOX + 0x10,
            MAILBOX_SENDER = VIDEOCORE_MAILBOX + 0x14,
            MAILBOX_STATUS = VIDEOCORE_MAILBOX + 0x18,
            MAILBOX_CONFIG = VIDEOCORE_MAILBOX + 0x1C,
            MAILBOX_WRITE = VIDEOCORE_MAILBOX + 0x20,
            MAILBOX_RESPONSE = 0x80000000,
            MAILBOX_FULL = 0x80000000,
            MAILBOX_EMPTY = 0x40000000
        };
    };
}

#endif