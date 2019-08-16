#include <SI_EFM8BB2_Register_Enums.h>
#include "stdio.h"
#include "InitDevice.h"
#include "spi.h"

unsigned short V;
unsigned char OSD_Data[15]={0};

extern unsigned char VOT_value[3];
extern unsigned char min_text[2];
extern unsigned char sec_text[2];
extern unsigned char minute;
extern unsigned char second;
extern unsigned char flymode;
extern unsigned char proto;
extern unsigned char index;
extern unsigned char lock;
extern unsigned char m1;
extern unsigned char m2;
extern unsigned char m3;
extern unsigned char m4;
extern unsigned char  kp[9];
extern unsigned char  ki[9];
extern unsigned char  kd[9];
extern unsigned char showcase;
extern unsigned char  pry[4];
extern unsigned char  chn[4];
extern unsigned char turtle;
extern void delay(unsigned char n);
extern unsigned char map;


void flight_window_data()
{
		lock = (OSD_Data[0]>>4) & 0x01;
	
		V = (OSD_Data[1] << 8) + OSD_Data[2];
		VOT_value[0] = (V/100) << 3;
		VOT_value[1] = (V%100/10) << 3;
		VOT_value[2] = (V%100%10) << 3; 
	
		min_text[0] = (minute/10)  << 3;
		min_text[1] = (minute%10)  << 3;	
		sec_text[0] = (second/10)  << 3;
		sec_text[1] = (second%10)  << 3;
	
		chn[1] = (OSD_Data[6] >>1) & 0x1;
		chn[2] = (OSD_Data[6] >>2) & 0x1;;
		chn[3] = (OSD_Data[6] >>3) & 0x1;;
		
		if(chn[1])
		{
			if(chn[2])
			{
					if(chn[3])
					{
						flymode = 2;
					}
					else
					{
						flymode = 3;
					}
			}
			else
			{
					if(chn[3])
					{
						flymode = 4;
					}
					else
					{
						flymode = 0;
					}
			}
		}
		else
		{
			if(!chn[2])
			{
				flymode = 1;
			}
		}
		
	
		proto = (OSD_Data[0]>>6) & 0x3;
		
		turtle = (OSD_Data[4]>>6) & 0x3;
}

void set_window_data()
{
		index = OSD_Data[4] & 0xf;
}

void pid_window_data()
{
		index = index = OSD_Data[4] & 0xf;
	
		kp[0] = (OSD_Data[5]/100) << 3;
		kp[1] = (OSD_Data[5]%100/10) << 3;
		kp[2] = (OSD_Data[5]%100%10) << 3;
		kp[3] = (OSD_Data[6]/100) << 3;
		kp[4] = (OSD_Data[6]%100/10) << 3;
		kp[5] = (OSD_Data[6]%100%10) << 3;
		kp[6] = (OSD_Data[7]/100) << 3;
		kp[7] = (OSD_Data[7]%100/10) << 3;
		kp[8] = (OSD_Data[7]%100%10) << 3;
		
		ki[0] = (OSD_Data[8]/100) << 3;
		ki[1] = (OSD_Data[8]%100/10) << 3;
		ki[2] = (OSD_Data[8]%100%10) << 3;
		ki[3] = (OSD_Data[9]/100) << 3;
		ki[4] = (OSD_Data[9]%100/10) << 3;
		ki[5] = (OSD_Data[9]%100%10) << 3;
		ki[6] = (OSD_Data[10]/100) << 3;
		ki[7] = (OSD_Data[10]%100/10) << 3;
		ki[8] = (OSD_Data[10]%100%10) << 3;

		kd[0] = (OSD_Data[11]/100) << 3;
		kd[1] = (OSD_Data[11]%100/10) << 3;
		kd[2] = (OSD_Data[11]%100%10) << 3;
		kd[3] = (OSD_Data[12]/100) << 3;
		kd[4] = (OSD_Data[12]%100/10) << 3;
		kd[5] = (OSD_Data[12]%100%10) << 3;
		kd[6] = (OSD_Data[13]/100) << 3;
		kd[7] = (OSD_Data[13]%100/10) << 3;
		kd[8] = (OSD_Data[13]%100%10) << 3;
		
}


void motor_window_data()
{
		index = index = OSD_Data[4] & 0xf;
	
		m1 = ((OSD_Data[3]>>4) & 0x01) << 3;
		m2 = ((OSD_Data[3]>>5) & 0x01) << 3;
		m3 = ((OSD_Data[3]>>6) & 0x01) << 3;
		m4 = ((OSD_Data[3]>>7) & 0x01) << 3;
}


void receiver_window_data()
{
	index = OSD_Data[4] & 0xf;
	map = (OSD_Data[4] >> 4) & 0xf;
	
	pry[0] = (OSD_Data[5] >>0) & 0x3;
	pry[1] = (OSD_Data[5] >>2) & 0x3;
	pry[2] = (OSD_Data[5] >>4) & 0x3;
	pry[3] = (OSD_Data[5] >>6) & 0x3;

	chn[0] = (OSD_Data[6] >>0) &0x1;
	chn[1] = (OSD_Data[6] >>1)&0x1;
	chn[2] = (OSD_Data[6] >>2)&0x1;
	chn[3] = (OSD_Data[6] >>3)&0x1;
	
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
		SCON0_TI = 1;
		IE_EA = 1;
		P1MDIN |= P1MDIN_B5__DIGITAL;
		P1SKIP |= P1SKIP_B5__NOT_SKIPPED;
		P1MDOUT |= P1MDOUT_B5__OPEN_DRAIN;

		 while (1)
		 {	
				Read_Data(OSD_Data,15); 
				delay(250);
				if((OSD_Data[0] & 0x0f) == 0x0f)
				{
					if(OSD_Data[14] == OSD_checksum(OSD_Data))
					{
						showcase = OSD_Data[3] & 0x0f;

						switch (showcase)
						{
							case 0:
								flight_window_data();
								break;
							case 1:
								set_window_data();
								break;
							case 2:
								pid_window_data();
								break;
							case 3:
								motor_window_data();
								break;
							case 4:
								receiver_window_data();
							break;
							default:
								break;
						}
					}
				}
		 }
}
