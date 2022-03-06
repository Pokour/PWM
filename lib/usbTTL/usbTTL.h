#ifndef usbTTL
#define usbTTL

#endif



void USART_init(uint16_t ubrr_value);

unsigned char USART_Receive(void);

void USART_Transmit(unsigned char data);

void USART_Transmit_String(unsigned char s[]);
