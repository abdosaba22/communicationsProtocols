
/*
 * USART.c
 *
 * Created: 8/16/2022 2:19:45 PM
 *  Author: DELL
 */ 
#include "USART.h"

void USART_init(){
	UBRRL=103;
	SETBIT(UCSRB,TXEN);
	SETBIT(UCSRB,RXEN);
	SETBIT(UCSRC,UCSZ0);
	SETBIT(UCSRC,UCSZ1);
	SETBIT(UCSRB,RXCIE);
	SETBIT(SREG,7);
}
uint8_t USART_Recieve_char(){
	return UDR;
}
//void USART_Recieve_string(uint8_t *){}
//void USART_Transmit_char(uint8_t ){}
//void USART_Transmit_string(uint8_t *){}
