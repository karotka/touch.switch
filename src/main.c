#define F_CPU 1200000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "tinytouchlib.h"

volatile uint8_t status;



void cpuInit(void) {
    DDRB = 0x00;

    /** output pins */
    DDRB |= (1 << PB4);
    sei();
    tinytouch_init();
}

int main(void) {

    cpuInit();

    PORTB |= 1 << PB4;

    for(;;) {
        status = tinytouch_sense();

        if (status == tt_push) {
            PORTB ^= (1 << PB4);
            _delay_ms(400);
        }
    }
}
