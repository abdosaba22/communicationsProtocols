/*
 * SPI.h
 *
 * Created: 8/22/2022 1:43:27 PM
 *  Author: DELL
 */ 
#ifndef SPI_H_
#define SPI_H_

#include "header.h"

#define SS PB4
#define MOSI PB5
#define MISO PB6
#define SCK PB7

void SPI_init_Master(void);
void SPI_init_Slave(void);
void SPI_Send_char(uint8_t);
uint8_t SPI_Recieve_char();


#endif
