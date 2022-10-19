/*
 * SPI.c
 *
 * Created: 8/22/2022 1:43:12 PM
 *  Author: DELL
 */ 
#include "SPI.h"

void SPI_init_Master(void){
	DDRB |= 1<<SS |1<<MOSI | 1<<SCK; //O/P in master - MISO I/P
	SETBIT(SPCR,DORD);
	SETBIT(SPCR,MSTR);
	SETBIT(SPCR,SPE);
}
void SPI_init_Slave(void){
	SETBIT(DDRB,MISO);
	SETBIT(SPCR,DORD);
	SETBIT(SPCR,SPE);
	
}
void SPI_Send_char(uint8_t data){
	SPDR = data;
	while(READBIT(SPSR,SPIF) == 0);
}
uint8_t SPI_Recieve_char(){
	while(READBIT(SPSR,SPIF) == 0);
	return SPDR;
}