#include <avr/io.h>
#include <util/delay.h>



void USART_init(uint16_t ubrr_value){
    UBRRL = ubrr_value;
    UBRRH = (ubrr_value >> 8);

    //UCCSRC |=(1<<URSEL);
    UCSRC |= (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
    UCSRB |= (1<<RXEN) | (1<<TXEN) | (1<<RXCIE);
}

unsigned char USART_Receive(void){
    while(!(UCSRA & (1<<RXC)));
    return UDR;
}

void USART_Transmit(unsigned char data){
    while(!(UCSRA & (1<<UDRE)));
    UDR = data;
}

void USART_Transmit_String(unsigned char s[]){
    int i = 0;
    while(s[i] != 0x00){
        USART_Transmit(s[i]);
        i++;
    }
}