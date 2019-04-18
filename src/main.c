// Resources:
//   SYSCLK - 24.5 MHz HFOSC0 / 1
//   UART0  - 115200 baud, 8-N-1
//   Timer1 - UART0 clock source
//   P0.4   - UART0 TX
//   P0.5   - UART0 RX
//
//   P0.6   - SPI SCK
//   P0.7   - SPI MISO
//   P1.0   - SPI MOSI
//   P1.1   - SPI NSS


//   P0.2   _ExternInterruput

//   P1.6   ADC 采集引脚
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB2_Register_Enums.h>
#include "stdio.h"
#include "InitDevice.h"
#include "spi.h"
SI_SBIT (LED_GREEN, SFR_P1, 4);           // green LED
//extern int count;

//void UART1_SendData(char dat)
//{
//	IE &= ~(1<<4);
//	SBUF0 = dat;
//	while(!(SCON0 & 1<<1));    //
//	SCON0 &= ~(1<<1);          //
//	IE |= (1<<4);
//}

////UART0  
//void UART1_SendString(char *s)
//{
//	while(*s)   //
//	{
//		UART1_SendData(*s++);
//	}
//}


//char putchar(char c)
//{
//	UART1_SendData(c);
//	return c;
//}
//unsigned int mV;
unsigned int V;
unsigned char lock;
extern unsigned char VOT_value[];
extern unsigned char min_text[2];
extern unsigned char sec_text[2];
extern unsigned short minute,second;
extern unsigned short rising_count;                        //记录上升沿次数
unsigned char OSD_Data[4]={0};

/*显示时间到屏幕*/
void Show_time(unsigned char dat,char buff[])
{
		buff[0] = dat/10;
	  buff[1] = dat%10;
}

/*显示电压到屏幕*/
void Show_Voltage(int value,char buff[])
{
		buff[0] = value/100;
		buff[1] = value%100/10;
		buff[2] = value%100%10;
}
/*
//BB21ADC读取

void Get_voltage()
{
	 static uint32_t accumulator = 0;     // Accumulator for averaging
   static uint16_t measurements = 2048; // Measurement counter
   uint32_t result = 0;
//   uint32_t mV;                       // Measured voltage in mV
   uint8_t SFRPAGE_save;

	 ADC0CN0 |= 0x01<<4;       //清除标志位
   ADC0CN0_ADINT = 0;                   // Clear ADC0 conv. complete flag

   accumulator += ADC0;
   measurements--;

   if(measurements == 0)
   {
	  measurements = 2048;
	  result = accumulator / 2048;
	  accumulator = 0;
	  mV =  (result * 3300) / 1023;
	  SFRPAGE_save = SFRPAGE;
	  SFRPAGE = LEGACY_PAGE;
		Show_Voltage(mV,VOT_value);
	  SFRPAGE = SFRPAGE_save;
   }
}
*/
//int i;
void main (void)
{
	/*关闭看门狗*/
	 WDTCN = 0xDE; //First key
	 WDTCN = 0xAD; //Second key
	
   CLOCK_Init();
	 EX0_Init();
   Timer0_Init();
	 SPI0_Init();
	 ADC_Init();
   SCON0_TI = 1;                       // This STDIO library requires TI to
	 IE_EA = 1;
	 P1MDIN |= P1MDIN_B5__DIGITAL;
	 P1SKIP |= P1SKIP_B5__NOT_SKIPPED;
	 P1MDOUT |= P1MDOUT_B5__OPEN_DRAIN;
   while (1)
   {
			Read_Data(OSD_Data,4);          //读取飞控要显示再OSD的数据
		  if(OSD_Data[3] == OSD_checksum(OSD_Data))
			{
					if(OSD_Data[0] == 1)        //电压数据
					{
							V = (OSD_Data[1] << 8) + OSD_Data[2];
					}
					
					if(OSD_Data[0] == 2)        //解锁标志
					{
							lock = (OSD_Data[1] << 8) + OSD_Data[2];
					}
			}
			//Get_voltage();
				Show_Voltage(V,VOT_value);
		  Show_time(second,sec_text);
			Show_time(minute,min_text);
   }
}
