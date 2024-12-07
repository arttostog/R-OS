#include <./drivers/uart/ros_uart.h>

using namespace ROS;

void Uart::init() {
    volatile uint32_t* uart0Cr = ((volatile uint32_t*) UART0_CR),
        *gpfsel1 = ((volatile uint32_t*) Gpio::GPFSEL1),
        *gppudclk0 = ((volatile uint32_t*) Gpio::GPPUDCLK0);

    *uart0Cr = 0;

    MailBox::mailbox[0] = 9 * 4;
    MailBox::mailbox[1] = MailBox::MAILBOX_REQUEST;
    MailBox::mailbox[2] = MailBox::MAILBOX_TAG_SETCLKRATE;
    MailBox::mailbox[3] = 12;
    MailBox::mailbox[4] = 8;
    MailBox::mailbox[5] = 2;
    MailBox::mailbox[6] = 4 * Clock::MHZ;
    MailBox::mailbox[7] = 0;
    MailBox::mailbox[8] = MailBox::MAILBOX_TAG_LAST;
    MailBox::call(MailBox::MAILBOX_CHANNEL_PROP);

    uint32_t newGpfsel1 = *gpfsel1;
    newGpfsel1 &= ~((7 << 12) | (7 << 15));
    newGpfsel1 |= (4 << 12) | (4 << 15);
    *gpfsel1 = newGpfsel1;
    *((volatile uint32_t*) Gpio::GPPUD) = 0;
    Clock::delayByCycles(150);
    *gppudclk0 = (1 << 14) | (1 << 15);
    Clock::delayByCycles(150);
    *gppudclk0 = 0;

    *((volatile uint32_t*) Uart::UART0_ICR) = 0x7FF;
    *((volatile uint32_t*) Uart::UART0_IBRD) = 2;
    *((volatile uint32_t*) Uart::UART0_FBRD) = 0xB;
    *((volatile uint32_t*) Uart::UART0_LCRH) = 0x7 << 4;
    *uart0Cr = 0x301;
}

uint32_t Uart::read(IN uint64_t address){
    return *((volatile uint32_t*) address);
}

void Uart::write(IN uint64_t address, IN uint32_t data) {
    *((volatile uint32_t*) address) = data;
}