#include <avr/io.h>
#include <util/delay.h>
#include <test.h>

int main(void) {

  // set PORTB as OUTPUT
  DDRB = 0xFF;
  DDRD = 0x00;
  PORTD = 0xFF;

  while(1) {

    ledChaser();
    
  }
}