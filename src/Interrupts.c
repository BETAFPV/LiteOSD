// USER INCLUDES
#include <SI_EFM8BB2_Register_Enums.h>
#include "show.h"


//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------
unsigned char  flag = 0;
unsigned short  rising_count=0;
unsigned char  minute=0;
unsigned char  second=0;
unsigned char UART_Buffer[12] = {0};
unsigned char UART_Buffer_Size = 0;
unsigned short  line = 0;

extern unsigned char  lock;
extern unsigned char  min_text[2];
extern unsigned char  sec_text[2];
extern unsigned char  showcase;


//-----------------------------------------------------------------------------
// INT0_ISR
//-----------------------------------------------------------------------------
//
// INT0 ISR Content goes here. Remember to clear flag bits:
// TCON::IE0 (External Interrupt 0)
//
// Whenever a negative edge appears on P0.2.
// The interrupt pending flag is automatically cleared by vectoring to the ISR
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (INT0_ISR, INT0_IRQn)
{
    if(flag == 0) {
        TH0 = 0x00;
        TL0 = 0x00;
        IT01CF = IT01CF_IN0PL__ACTIVE_LOW | IT01CF_IN0SL__P0_2;
        if(lock == 1 && showcase == 0) {
            rising_count++;
        }

        if(rising_count>=16129) {
            rising_count = 0;
            second+=1;
            if(second >= 60) {
                second = 0;
                minute++;
                if(minute>=60) {
                    minute = 0;
                }
            }

            min_text[0] = (minute/10)  << 3;
            min_text[1] = (minute%10)  << 3;
            sec_text[0] = (second/10)  << 3;
            sec_text[1] = (second%10)  << 3;
        }
        flag = 1;
    } else {
        if((TH0<<8 | TL0) > 490) {
            line = 0;
        }
        switch (showcase) {
        case 0:
            flight_window(line);
            break;

        case 1:
            set_window(line);
            break;

        case 2:
            config_window(line);
            break;

        case 3:
            layout_window(line);
            break;

        case 4:
            vtx_window(line);
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
unsigned char byte = 0;
unsigned char len = 0;
unsigned char uart_flag = 0;

SI_INTERRUPT (UART0_ISR, UART0_IRQn)
{
    if (SCON0_RI == 1) {
        SCON0_RI = 0;
        byte = SBUF0;
        if(UART_Buffer_Size==0 && (byte & 0x0f) == 0X0F) {
            UART_Buffer[UART_Buffer_Size] = byte;
            UART_Buffer_Size ++;
        } else if (UART_Buffer_Size >0 && UART_Buffer_Size <12) {
            UART_Buffer[UART_Buffer_Size] = byte;
            UART_Buffer_Size ++;
        }
        if(UART_Buffer_Size == 12) {
            UART_Buffer_Size = 0;
        }
    }
}


