#include <./drivers/ros_mailbox.h>

using ROS::MailBox;

volatile uint32_t MailBox::mailbox[36] = { };

bool MailBox::call(IN byte_t channel) {
    uint32_t request = ((uint32_t) (((uint64_t) &mailbox) &~0xF)) | (channel & 0xF);

    volatile uint32_t* status = (volatile uint32_t*) MAILBOX_STATUS;

    while (*status & MAILBOX_FULL)
        continue;
    
    *((volatile uint32_t*) MAILBOX_WRITE) = request;

    while (true) {
        while (*status & MAILBOX_EMPTY)
            continue;

        if (request == *((volatile uint32_t*) MAILBOX_READ))
            return mailbox[1] == MAILBOX_RESPONSE;        
    }
}