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

unsigned int V;
extern unsigned char lock;
extern unsigned char flymode;

idata unsigned  int kp1;
idata unsigned  int kp2;
idata unsigned  int kp3;

idata unsigned  int ki1;
idata unsigned  int ki2;
idata unsigned  int ki3;

idata unsigned  int kd1;
idata unsigned  int kd2;
idata unsigned  int kd3;

extern unsigned char roll1;
extern unsigned char pitch1;
extern unsigned char yaw1;
extern unsigned char throttle1;
extern unsigned char aetr_or_taer;

extern idata unsigned char ARMING;		//ch5
extern idata unsigned char LEVELMODE;	//ch6
extern idata unsigned char RACEMODE;	//ch7
extern idata unsigned char HORIZON;		//ch8

idata unsigned char m11;
idata unsigned char m22;
idata unsigned char m33;
idata unsigned char m44;

extern unsigned char m1;
extern unsigned char m2;
extern unsigned char m3;
extern unsigned char m4;

extern unsigned char VOT_value[3];
extern unsigned char state_value[3];
extern unsigned char   kp[9];
extern unsigned char   ki[9];
extern unsigned char   kd[9];
extern unsigned char min_text[2];
extern unsigned char sec_text[2];
extern unsigned short minute,second;
extern unsigned short rising_count;      //记录上升沿次数
idata unsigned char OSD_Data[16]={0};
extern void delay(int n);
extern unsigned char flight_window;
extern unsigned char index;
extern unsigned char turtle;
extern unsigned char proto;
extern unsigned char osd_class;
idata unsigned char state = 0,proto_class = 0;
idata unsigned char index_turtle = 0;

/*显示时间到屏幕*/
void Show_time(unsigned char dat,char buff[])
{
	buff[0] = (dat/10)  << 3;
	buff[1] = (dat%10)  << 3;
}

/*显示电压到屏幕*/
void Show_Voltage(int value,char buff[])
{
	buff[0] = (value/100) << 3;
	buff[1] = (value%100/10) << 3;
	buff[2] = (value%100%10) << 3;
}

/*显示pid到屏幕*/
void Show_PID(int pid1,int pid2,int pid3,char buff[])
{
	buff[0] = (pid1/100) << 3;
	buff[1] = (pid1%100/10) << 3;
	buff[2] = (pid1%100%10) << 3;
	buff[3] = (pid2/100) << 3;
	buff[4] = (pid2%100/10) << 3;
	buff[5] = (pid2%100%10) << 3;
	buff[6] = (pid3/100) << 3;
	buff[7] = (pid3%100/10) << 3;
	buff[8] = (pid3%100%10) << 3;
}

void Show_Moto(unsigned char state)
{
	flight_window = (state>>4) & 0x01;
	lock = (state>>5) & 0x01;
	flymode =(state>>6) & 0xf;
	m1 = (state & 0x01) << 3;
	m2 = ((state>>1) & 0x01) << 3;
	m3 = ((state>>2) & 0x01) << 3;
	m4 = ((state>>3) & 0x01) << 3;
}


void  Show_prot(unsigned char prot)
{
		osd_class = prot & 0x0f;
		proto = prot >> 4;
}

void  Show_index(unsigned char index_turtle)
{
		index = index_turtle & (~0x80);
		turtle = index_turtle >> 7;
}

void main (void)
{
	/*关闭看门狗*/
		WDTCN = 0xDE; //First key
		WDTCN = 0xAD; //Second key
	
		CLOCK_Init();
		EX0_Init();
		Timer0_Init();
		SPI0_Init();
		SCON0_TI = 1;                       // This STDIO library requires TI to
		IE_EA = 1;
		P1MDIN |= P1MDIN_B5__DIGITAL;
		P1SKIP |= P1SKIP_B5__NOT_SKIPPED;
		P1MDOUT |= P1MDOUT_B5__OPEN_DRAIN;

		 while (1)
		 {
				Read_Data(OSD_Data,16);          //读取飞控要显示再OSD的数据
				if(OSD_Data[15] == OSD_checksum(OSD_Data))
				{
					if(osd_class == 0)
						{
						if(OSD_Data[0] == 0x88)
						{
							V = (OSD_Data[1] << 8) + OSD_Data[2];
							roll1 =  OSD_Data[3];
							pitch1 =  OSD_Data[4];
							yaw1 =  OSD_Data[5];
							throttle1 =  OSD_Data[6];
							ARMING =  OSD_Data[7];
							LEVELMODE =  OSD_Data[8];
							RACEMODE =  OSD_Data[9];
							HORIZON =  OSD_Data[10];
							aetr_or_taer =  OSD_Data[11];
							state = OSD_Data[12];
							proto_class = OSD_Data[13];
							index_turtle = OSD_Data[14];
						}
					}
					else
						{	if(OSD_Data[0] == 0x88)
							{
							V = (OSD_Data[1] << 8) + OSD_Data[2];

							kp1 =  OSD_Data[3];
							kp2 =  OSD_Data[4];
							kp3 =  OSD_Data[5];
							ki1 =  OSD_Data[6];
							ki2 =  OSD_Data[7];
							ki3 =  OSD_Data[8];
							kd1 =  OSD_Data[9];
							kd2 =  OSD_Data[10];
							kd3 =  OSD_Data[11];	
					
							state = OSD_Data[12];
							proto_class = OSD_Data[13];
							index_turtle = OSD_Data[14];
						}
					}
			}
	
			Show_PID(kp1,kp2,kp3,kp);
			Show_PID(ki1,ki2,ki3,ki);
			Show_PID(kd1,kd2,kd3,kd);
			Show_Voltage(V,VOT_value);
			Show_Moto(state);
			Show_prot(proto_class);
			Show_time(minute,min_text);
			Show_time(second,sec_text);
			Show_index(index_turtle);
	}
}
