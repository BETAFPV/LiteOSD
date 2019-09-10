
// Resources:
//   SYSCLK - 32.667 MHz HFOSC0 / 1
//   UART0  - 115200 baud, 8-N-1
//   Timer1 - UART0 clock source
//   P0.4   - UART0 TX
//   P0.5   - UART0 RX

// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB2_Register_Enums.h>
#include "retargetserial.h"
#include "InitDevice.h"

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------
// Variables in Interrupts.c

unsigned short V;
unsigned char  min_text[2] = {0};
unsigned char  sec_text[2] = {0};
unsigned char  lock = 0;
unsigned char  showcase = 0;
unsigned char  VOT_value[3] = {0};
unsigned char  flymode = 0;
unsigned char  proto=1;
unsigned char  index=0;
unsigned char  m1 = 0;
unsigned char  m2 = 0;
unsigned char  m3 = 0;
unsigned char  m4 = 0;
unsigned char   kp[9] = {0};
unsigned char   ki[9] = {0};
unsigned char   kd[9] = {0};
unsigned char   pry[4] = {0};
unsigned char   chn[4] = {0};
unsigned char  turtle=0;
unsigned char  map=0;
unsigned char  vtx_power =0;
unsigned char  channel = 0;
unsigned char freq = 0;

extern unsigned char UART_Buffer[15];


uint8_t OSD_checksum(uint8_t UART_Buffer[])
{
		unsigned char i;
		unsigned char sum = 0;
     for (i = 0; i < 14;i++ )
		{
					sum += UART_Buffer[i];
		}
    return sum;
}


void flight_window_data()
{
	lock = (UART_Buffer[0]>>4) & 0x01;

		V = (UART_Buffer[1] << 8) + UART_Buffer[2];
		VOT_value[0] = (V/100) << 3;
		VOT_value[1] = (V%100/10) << 3;
		VOT_value[2] = (V%100%10) << 3;


		chn[1] = (UART_Buffer[6] >>1) & 0x1;
		chn[2] = (UART_Buffer[6] >>2) & 0x1;;
		chn[3] = (UART_Buffer[6] >>3) & 0x1;;

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


		proto = (UART_Buffer[0]>>6) & 0x3;

		turtle = (UART_Buffer[4]>>6) & 0x3;
}
 
void set_window_data()
{
		index = UART_Buffer[4] & 0xf;
}

void pid_window_data()
{
		index = index = UART_Buffer[4] & 0xf;

		kp[0] = (UART_Buffer[5]/100) << 3;
		kp[1] = (UART_Buffer[5]%100/10) << 3;
		kp[2] = (UART_Buffer[5]%100%10) << 3;
		kp[3] = (UART_Buffer[6]/100) << 3;
		kp[4] = (UART_Buffer[6]%100/10) << 3;
		kp[5] = (UART_Buffer[6]%100%10) << 3;
		kp[6] = (UART_Buffer[7]/100) << 3;
		kp[7] = (UART_Buffer[7]%100/10) << 3;
		kp[8] = (UART_Buffer[7]%100%10) << 3;

		ki[0] = (UART_Buffer[8]/100) << 3;
		ki[1] = (UART_Buffer[8]%100/10) << 3;
		ki[2] = (UART_Buffer[8]%100%10) << 3;
		ki[3] = (UART_Buffer[9]/100) << 3;
		ki[4] = (UART_Buffer[9]%100/10) << 3;
		ki[5] = (UART_Buffer[9]%100%10) << 3;
		ki[6] = (UART_Buffer[10]/100) << 3;
		ki[7] = (UART_Buffer[10]%100/10) << 3;
		ki[8] = (UART_Buffer[10]%100%10) << 3;

		kd[0] = (UART_Buffer[11]/100) << 3;
		kd[1] = (UART_Buffer[11]%100/10) << 3;
		kd[2] = (UART_Buffer[11]%100%10) << 3;
		kd[3] = (UART_Buffer[12]/100) << 3;
		kd[4] = (UART_Buffer[12]%100/10) << 3;
		kd[5] = (UART_Buffer[12]%100%10) << 3;
		kd[6] = (UART_Buffer[13]/100) << 3;
		kd[7] = (UART_Buffer[13]%100/10) << 3;
		kd[8] = (UART_Buffer[13]%100%10) << 3;

}


void motor_window_data()
{
		index = index = UART_Buffer[4] & 0xf;

		m1 = ((UART_Buffer[3]>>4) & 0x01) << 3;
		m2 = ((UART_Buffer[3]>>5) & 0x01) << 3;
		m3 = ((UART_Buffer[3]>>6) & 0x01) << 3;
		m4 = ((UART_Buffer[3]>>7) & 0x01) << 3;
}


void receiver_window_data()
{
	index = UART_Buffer[4] & 0xf;
	map = (UART_Buffer[4] >> 4) & 0xf;

	pry[0] = (UART_Buffer[5] >>0) & 0x3;
	pry[1] = (UART_Buffer[5] >>2) & 0x3;
	pry[2] = (UART_Buffer[5] >>4) & 0x3;
	pry[3] = (UART_Buffer[5] >>6) & 0x3;

	chn[0] = (UART_Buffer[6] >>0) &0x1;
	chn[1] = (UART_Buffer[6] >>1)&0x1;
	chn[2] = (UART_Buffer[6] >>2)&0x1;
	chn[3] = (UART_Buffer[6] >>3)&0x1;
}

void sa_window_data()
{
	index = UART_Buffer[4] & 0xf;
}


//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------
void main (void)
{
   enter_DefaultMode_from_RESET();

   IE_EA = 1;

   while(1)
   {
		 if((UART_Buffer[0] & 0x0f) == 0x0f)
		 {
			 if(UART_Buffer[14] == OSD_checksum(UART_Buffer))
			 {
					showcase = UART_Buffer[3] & 0x0f;
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
                            case 5:
								sa_window_data();
							default:
								break;
						}
				}
			}

   }
}
