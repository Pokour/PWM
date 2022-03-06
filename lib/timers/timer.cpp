#include <avr/io.h>
#include<avr/interrupt.h>

void Init_Timer0(void)
{
    // Set Timer0 to CTC mode
    TCCR0A |= (1 << WGM01);
    // Set Timer0 prescaler to 64
    TCCR0B |= (1 << CS01) | (1 << CS00);
    // Set Timer0 compare value to 125
    OCR0A = 125;
    // Enable Timer0 compare interrupt
    TIMSK0 |= (1 << OCIE0A);
}
