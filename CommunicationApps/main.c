/*
 * CommunicationApps.c
 *
 * Created: 8/16/2022 2:16:58 PM
 * Author : DELL
 */ 

#include "header.h"


int main(void)
{
    /* Replace with your application code */
    LCD_init();
	LCD_write_command(0x80);
	//USART_init();
	
	//SPI_init_Master();
	
	I2C_master_init();
	
	//CLRBIT(PORTB,SS);
	uint8_t a = 'a';
	
	while (1) 
    {	
		//SPI_Send_char(a);
		//_delay_ms(800);
		
		I2C_master_start_Cond();
		_delay_ms(500);
		
		I2C_master_write_addr(0x32);
		_delay_ms(50);
		I2C_master_write(a);
		_delay_ms(50);
		
		I2C_master_stop();
		_delay_ms(500);
		
		
		_delay_ms(500);
		I2C_master_start_Cond();
		_delay_ms(500);
		
		_delay_ms(50);
		I2C_master_write_addr(0x33);
		_delay_ms(50);
		I2C_master_write(a);
		_delay_ms(50);
	
		
		I2C_master_stop();
		_delay_ms(500);
		
		
		_delay_ms(500);
		I2C_master_start_Cond();
		_delay_ms(500);
		
		
		_delay_ms(50);
		I2C_master_Read_addr(0x32);
		_delay_ms(50);
		LCD_write_char(I2C_master_Read());
		_delay_ms(50);
	
		I2C_master_stop();
		_delay_ms(500);
		
		
		_delay_ms(500);
		I2C_master_start_Cond();
		_delay_ms(500);	
	
		_delay_ms(50);
		I2C_master_Read_addr(0x33);
		_delay_ms(50);
		LCD_write_char(I2C_master_Read());
		_delay_ms(50);
		
		I2C_master_stop();
		
		
	
		a++;
		_delay_ms(100);
	}
}
/*
ISR(USART_RXC_vect){
	LCD_write_char(USART_Recieve_char());
	UDR=0;
}*/

