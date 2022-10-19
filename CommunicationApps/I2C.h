/*
 * I2C.h
 *
 * Created: 8/25/2022 1:39:21 PM
 *  Author: DELL
 */ 
#ifndef I2C_H_

#define I2C_H_

#include "header.h"

#define I2C_START         0x08
#define I2C_REP_START     0x10
#define I2C_MT_SLA_W_ACK  0x18
#define I2C_MT_SLA_R_ACK  0x40
#define I2C_MT_DATA_ACK   0x28
#define I2C_MR_DATA_ACK   0x50
#define I2C_MR_DATA_NACK  0x58
#define I2C_SLA_W_MT_ACK  0x60
#define I2C_Arbitra_Lost  0x38
#define I2C_SLA_R_MR_ACK  0x60
 
void I2C_master_init(void);

void I2C_master_start_Cond(void);

void I2C_master_write_addr(uint8_t ID_Sla);

void I2C_master_Read_addr(uint8_t ID_Sla);

void I2C_master_write(uint8_t);

uint8_t I2C_master_Read(void);

void I2C_master_stop(void);

void I2C_slave_Init(uint8_t My_Add);

uint8_t I2C_slave_avialable(void);

uint8_t I2C_slave_read(void);

void I2C_slave_write(uint8_t data);

#endif