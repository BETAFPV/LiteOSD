#include <SI_EFM8BB2_Register_Enums.h>
#include "InitDevice.h"

void CLOCK_Init(void) 
{
	int i=0;
	CLKSEL = 0x00;         //24.5MHz 
	while(CLKSEL & 0x80 != 0x80);
	for(i=0;i<1000;i++);   //等待时钟稳定
	CLKSEL = 0x03;         //49MHz
	while(CLKSEL & 0x80 != 0x80);
}

/*外部中断初始化*/
void EX0_Init(void)
{
	XBR2 = 0x40;
	IT01CF = 0x0A;      
	IE |= 0x05;         
}

/*定时器0初始化*/
void Timer0_Init()
{
	CKCON0 |= 0x05;      //24.5MHz  1/24.5 us   
	TMOD |= 0x01;     
	TL0 = 0x00;
	TH0 = 0x00;
	TCON |= 0x10;  

}


/*SPI0 初始化*/
void SPI0_Init()
{
	P0MDOUT = 0x40;     //P0.6 SPI MOSI
	P0SKIP = 0x3F;
	P1MDOUT = 0x13;

	SFRPAGE = 0x00;
	XBR2 = 0x40;
	XBR0 = 0x02;        //SPI
	
	SPI0CKR = 0x02;       
	SPI0CFG |= 0x40;      
	SPI0CN0 |= 0x01;
}

/*ADC 初始化*/
void ADC_Init()
{
	XBR2 = 0x40;
	XBR0 |=0x01;
	
	ADC0MX = 0x0E;	      //weifeng modify
	
	//ADC0CF = 0x09;
	ADC0CF = 0x11;
	ADC0PWR = 0x4F;
	ADC0CN0 &= ~0x07;
	ADC0CN0 |= 0x80;	
}
//void UART_Init()
//{
//	  uint8_t TCON_save = TCON;
//		XBR2 = 0x40;
//	  XBR0 = 0x01;
//	  TCON &= 0x10 & 0x40;
//	  TH1 = 0x96;
//	  TCON = TCON_save;
//	
//	  CKCON0 = 0x08;
//	  TMOD = 0x20;
//	  TCON |= 0x40;
//	  SCON0 |= 0x10;    
//}
