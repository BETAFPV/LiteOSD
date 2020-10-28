#include <SI_EFM8BB2_Register_Enums.h>
#include "retargetserial.h"
#include "InitDevice.h"


unsigned char  showcase = 0;
unsigned char  min_text[2] = {0};
unsigned char  sec_text[2] = {0};
unsigned char  lock = 0;

extern unsigned char UART_Buffer[12];
extern void delay(unsigned char n);

void delayS(unsigned char n)
{
    unsigned char i;
    unsigned int j;
    for(i=0; i<n; i++)
        for(j=500000; j>0; j--)
            ;
}


uint8_t OSD_checksum(uint8_t UART_Buffer[])
{
    unsigned char i;
    unsigned char sum = 0;
    for (i = 0; i < 11; i++ ) {
        sum += UART_Buffer[i];
    }
    return sum;
}


void flight_window_data(void)
{





}


void set_window_data(void)
{



}

void config_window_data(void)
{


}



void layout_window_data(void)
{




}


void vtx_window_data(void)
{


}

void main (void)
{
    enter_DefaultMode_from_RESET();

    IE_EA = 1;
    delayS(250);
    SPI0CKR = (1 << SPI0CKR_SPI0CKR__SHIFT);

    while(1)
    {
        if(UART_Buffer[11] == OSD_checksum(UART_Buffer)) {
            showcase = (UART_Buffer[0]>>4) & 0x0f;
            switch (showcase) {
            case 0:
                flight_window_data();
                break;

            case 1:
                set_window_data();
                break;

            case 2:
                config_window_data();
                break;

            case 3:
                layout_window_data();
                break;

            case 4:
                vtx_window_data();
                break;
            }
        }
    }
}

















