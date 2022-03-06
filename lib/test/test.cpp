#include <avr/io.h>
#include <util/delay.h>



void ledChaser(){
    if (!(PIND & (1 << 0))) {
        // turn on LED
        for (int i = 0; i < 8; i++)        {
            PORTB = 0b00000001 << i;
            _delay_ms(2);
        }
    } else {
        // turn off LED
        PORTB = 0x00;
    }
}