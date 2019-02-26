//CLK   P1.2
//CSN   P1.3
//DATA  P1.5

#ifndef __SPI_H_
#define __SPI_H_

#include "SI_EFM8BB2_Defs.h"

sbit CLK = P1^2;
sbit CSN  = P1^3;
sbit IO  = P1^5;

void spi_cson(void);
void spi_csoff(void);
void spi_sendbyte(unsigned char dat);
unsigned char spi_recvbyte(void);
void Read_Data( uint8_t *readData,  uint8_t length);
void Tx_Data(uint8_t *TxData ,uint8_t length);
uint8_t OSD_checksum(uint8_t OSD_DATA[]);
#endif