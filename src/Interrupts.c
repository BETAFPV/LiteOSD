// USER INCLUDES			
#include <SI_EFM8BB2_Register_Enums.h>
#include "show.h"

unsigned char flag = 0;
unsigned short line = 0;

unsigned char minute=0;
unsigned char second=0;
unsigned char min_text[2] = {0};
unsigned char sec_text[2] = {0};
unsigned short rising_count=0;
unsigned char lock = 0;
unsigned char showcase = 0;
unsigned char VOT_value[3] = {0};
unsigned char flymode = 0;
unsigned char proto=1;
unsigned char index=0;
unsigned char m1 = 0;
unsigned char m2 = 0;
unsigned char m3 = 0;
unsigned char m4 = 0;
unsigned char  kp[9] = {0};
unsigned char  ki[9] = {0};
unsigned char  kd[9] = {0};
unsigned char  pry[4] = {0};
unsigned char  chn[4] = {0};
unsigned char turtle=0;
unsigned char map=0;

unsigned char UART_Buffer[15] = {0};
unsigned char UART_Buffer_Size = 0;

SI_INTERRUPT (INT0_ISR, INT0_IRQn)
{
	 
	 if(flag == 0)
	 {
			TH0 = 0x00;
			TL0 = 0x00;
		  IT01CF = IT01CF_IN0PL__ACTIVE_LOW | IT01CF_IN0SL__P0_2;
			if(lock == 1 && showcase == 0)
			{
					rising_count++;
			}

			if(rising_count>=16129)
			{
					rising_count = 0;
					second+=1;
					if(second >= 60)
					{
						second = 0;
						minute++;
						if(minute>=60)
						{
								minute = 0;
						}
					}

		        min_text[0] = (minute/10)  << 3;
		        min_text[1] = (minute%10)  << 3;
		        sec_text[0] = (second/10)  << 3;
		        sec_text[1] = (second%10)  << 3;
			}
		  flag = 1;
	 }
	 else
	 {
		 	if((TH0<<8 | TL0) > 490)
			{
				line = 0;
			}
			switch (showcase)
			{
				case 0:
					flight_window(line);
					break;
				case 1:
					set_window(line);
					break;
				case 2:
					pid_window(line);
					break;
				case 3:
					motor_window(line);
					break;
				case 4:
					receiver_window(line);
					break;
				case 5:
					sa_window(line);
					break;
				default:
					break;
			}
		 	SPI0DAT = 0x00;
			line++;
			IT01CF = IT01CF_IN0PL__ACTIVE_HIGH | IT01CF_IN0SL__P0_2;
			flag=0;
	}
	
}


//-----------------------------------------------------------------------------
// UART0_ISR
//-----------------------------------------------------------------------------
//
// UART0 ISR Content goes here. Remember to clear flag bits:
// SCON0::RI (Receive Interrupt Flag)
// SCON0::TI (Transmit Interrupt Flag)
//
//-----------------------------------------------------------------------------

SI_INTERRUPT (UART0_ISR, UART0_IRQn)
{
	   if (SCON0_RI == 1)
	   {
				SCON0_RI = 0;
	      if(UART_Buffer_Size < 15)
	      {
					UART_Buffer[UART_Buffer_Size] = SBUF0;
					UART_Buffer_Size ++;
	      }
	      else
	      {
	    	  UART_Buffer_Size =0;
					
	      }
				
	   }
	   if (SCON0_TI == 1)                        // Check if transmit flag is set
	   {
	      SCON0_TI = 0;
	   }
}

