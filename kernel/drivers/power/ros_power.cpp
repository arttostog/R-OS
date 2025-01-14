#include <./kernel/drivers/power/ros_power.h>

using namespace ROS;

void Power::shutdown() {
    Logger::log(Logger::INFO, "Shutdowning...");
    for (uint32_t i = 0; i < 16; ++i) {
        MailBox::mailbox[0] = 8 * 4;
        MailBox::mailbox[1] = MailBox::MAILBOX_REQUEST;
        MailBox::mailbox[2] = MailBox::MAILBOX_TAG_SETPOWER;
        MailBox::mailbox[3] = 8;
        MailBox::mailbox[4] = 8;
        MailBox::mailbox[5] = i;
        MailBox::mailbox[6] = 0;
        MailBox::mailbox[7] = MailBox::MAILBOX_TAG_LAST;
        MailBox::call(MailBox::MAILBOX_CHANNEL_PROP);
    }

    *((volatile uint32_t*) Gpio::GPFSEL0) = 0;
    *((volatile uint32_t*) Gpio::GPFSEL1) = 0;
    *((volatile uint32_t*) Gpio::GPFSEL2) = 0;
    *((volatile uint32_t*) Gpio::GPFSEL3) = 0;
    *((volatile uint32_t*) Gpio::GPFSEL4) = 0;
    *((volatile uint32_t*) Gpio::GPFSEL5) = 0;
    *((volatile uint32_t*) Gpio::GPPUD) = 0;

    volatile uint32_t* gppudclk0 = ((volatile uint32_t*) Gpio::GPPUDCLK0),
        *gppudclk1 = ((volatile uint32_t*) Gpio::GPPUDCLK1);

    Clock::delayByCycles(150);
    *gppudclk0 = 0xffffffff;
    *gppudclk1 = 0xffffffff;
    Clock::delayByCycles(150);
    *gppudclk0 = 0;
    *gppudclk1 = 0;

    uint64_t newPmRsts = *((volatile uint32_t*) POWER_MODE_RSTS);
    newPmRsts &= ~0xFFFFFAAA;
    newPmRsts |= 0x555;

    *((volatile uint32_t*) POWER_MODE_RSTS) = POWER_MODE_WDOG_MAGIC | newPmRsts;
    *((volatile uint32_t*) POWER_MODE_WDOG) = POWER_MODE_WDOG_MAGIC | 10;
    *((volatile uint32_t*) POWER_MODE_RSTC) = POWER_MODE_WDOG_MAGIC | POWER_MODE_RSTC_FULL_RESET;
}