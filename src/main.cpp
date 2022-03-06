#include <avr/io.h>
#include <util/delay.h>
#include <test.h>
#include <usbTTL.h>
// #include <timer.h>

#define F_CPU 1000000UL		/* Define frequency here its 1MHz */
#define USART_BAUDRATE 9600
// #define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#define BAUD_PRESCALE ((F_CPU)/(USART_BAUDRATE * 16UL)-1)

int main(void) {

  // set PORTB as OUTPUT
  // DDRB = 0xFF;
  // DDRD = 0x00;
  // PORTD = 0xFF;
  // initialize USB
  USART_init(6.2);

  while(1) {

    // ledChaser();

    // USART_Transmit('Z');
    USART_Transmit_String("Hello World!\n");
    _delay_ms(100);
    
  }
}