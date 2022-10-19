/*
 * I2C.c
 *
 * Created: 8/25/2022 1:39:10 PM
 *  Author: DELL
 */ 
#include "I2C.h"

void I2C_master_init(void){
	TWBR=12; //SCL = 400Khz
	TWSR=0x00; // Clear SR
}

void I2C_master_start_Cond(void){
	SETBIT(TWCR,TWINT);
	SETBIT(TWCR,TWSTA);
	SETBIT(TWCR,TWEN);
	while( READBIT(TWCR,TWINT) == 0);
	
	while(( TWSR & (0xF8) )!= I2C_START);
}


void I2C_master_write_addr(uint8_t ID_Sla){
	TWDR = ID_Sla<<1;
	SETBIT(TWCR,TWINT);
	SETBIT(TWCR,TWEN);
	
	while( READBIT(TWCR,TWINT) == 0);
	while ((TWSR & (0xF8)) !=I2C_MT_SLA_W_ACK);
}

void I2C_master_Read_addr(uint8_t ID_Sla){
	TWDR = ID_Sla<<1;
	SETBIT(TWDR,0);
	SETBIT(TWCR,TWINT);
	SETBIT(TWCR,TWEN);
	
	while( READBIT(TWCR,TWINT) == 0);
	while ((TWSR & (0xF8)) !=I2C_MT_SLA_R_ACK);

}

void I2C_master_write(uint8_t dataa){
	TWDR = dataa; // Load data
	TWCR = 1<<TWINT | 1<<TWEN; //overwrite & other bits = 0 & start transmission
	
	while(READBIT(TWCR,TWINT) == 0);// wait until ending of transmission
	while ((TWSR & (0xF8)) != I2C_MT_DATA_ACK );
}


uint8_t I2C_master_Read(void){
	TWDR=0;
	SETBIT(TWCR,TWINT);
	SETBIT(TWCR,TWEN);
	while(READBIT(TWCR,TWINT) == 0); 
	while( (TWSR & (0xF8)) != 0x58) ;
	return TWDR;
}

void I2C_master_stop(void){
	TWCR = 1<<TWINT | 1<<TWEN | 1<<TWSTO;
}


void I2C_slave_Init(uint8_t My_Add){
	TWAR = My_Add<<1; // 7 bit in  MSB
	TWCR  = (1<<TWEN) | (1<<TWEA);
}


uint8_t I2C_slave_avialable(void){
	TWCR  = (1<<TWEN) | (1<<TWINT) |(1<<TWEA); // set TWEA to enable acknowledge
	while(READBIT(TWCR,TWINT) == 0); //wait
	
	while ((TWSR & (0xF8)) != I2C_SLA_W_MT_ACK && (TWSR & (0xF8)) != I2C_SLA_R_MR_ACK)	{
		TWCR  = (1<<TWEN) | (1<<TWINT) |(1<<TWEA);
		while(READBIT(TWCR,TWINT) == 0);
	}
	if((TWSR & (0xF8)) == I2C_SLA_W_MT_ACK) return 1; // read
	else return 0;	

}

uint8_t I2C_slave_read(void){
		TWCR  = (1<<TWEN) | (1<<TWINT) |(1<<TWEA);
		while(READBIT(TWCR,TWINT) == 0);
		while( (TWSR & (0xF8)) != 0x80);
		
		return TWDR;
}

void I2C_slave_write(uint8_t data){
	TWDR = data; // Load data
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA) ; //overwrite & other bits = 0 & start transmission
	while(READBIT(TWCR,TWINT) == 0);
	while( (TWSR & (0xF8)) != 0xC0 );
	

}
 