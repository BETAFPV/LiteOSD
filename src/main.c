#include <SI_EFM8BB2_Register_Enums.h>
#include "retargetserial.h"
#include "InitDevice.h"


unsigned char  showcase = 0;
unsigned char  min_text[2] = {0};
unsigned char  sec_text[2] = {0};
unsigned char  lock = 0;
unsigned char   chn[4] = {0};
unsigned char  mode = 0;
unsigned char failsafe=1;
unsigned char turtlemode = 0;
unsigned char  flymode = 0;
unsigned short V;
unsigned char  VOT_value[3] = {0};
unsigned char  low_vol= 1;
unsigned char  rx_index = 0;
unsigned char rx_show=1;
unsigned char mode_show=1;
unsigned char vol_show=1;
unsigned char   ochn[4] = {0};
unsigned char   rx0[3] = {0};
unsigned char   rx1[3] = {0};
unsigned char   rx2[3] = {0};
unsigned char   rx3[3] = {0};
unsigned char cur_index;
unsigned short rates = 0;
unsigned short rates_yaw = 0;
unsigned char rate[4] = {0};
unsigned char rate_yaw[4] = {0};
unsigned char  acc_cali= 0;
unsigned char rgb_led = 0;
unsigned char vtx_index = 0;
unsigned char band_index = 0;



extern unsigned char UART_Buffer[13];
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
    for (i = 0; i < 12; i++ ) {
        sum += UART_Buffer[i];
    }
    return sum;
}


void flight_window_data(void)
{
	  chn[0] = ((UART_Buffer[1] >>0) & 0x3)? 10 : 0;
    lock  = chn[0];
    chn[1] = ((UART_Buffer[1] >>2) & 0x3)? 12 : 0;
    chn[2] = ((UART_Buffer[1] >>4) & 0x3)? 14 : 0;
    chn[3] = ((UART_Buffer[1] >>6) & 0x3)? 16 : 0;
    
    
    mode = UART_Buffer[2] & 0x01;
    failsafe = (UART_Buffer[2]>>1)&0x01;
    turtlemode = (UART_Buffer[2]>>2)&0x01;
    flymode = (UART_Buffer[2] >>4) & 0x0f;
    
    V = (UART_Buffer[3] << 8) + UART_Buffer[4];
    VOT_value[0] = (V/100)<< 1;
    VOT_value[1] = (V%100/10)<< 1;
    VOT_value[2] = (V%100%10)<< 1;

    low_vol = UART_Buffer[5] &0x0f;
    rx_index = (UART_Buffer[5]>>4)&0x0f;
    
    vol_show = (UART_Buffer[6] >>0) & 0x1;
    rx_show = (UART_Buffer[6] >>1) & 0x1;
    mode_show = (UART_Buffer[6] >>2) & 0x1;
    
    if(rx_show)
    {
        ochn[0] = (UART_Buffer[6] >>4) & 0x1;
        ochn[1] = (UART_Buffer[6] >>5) & 0x1;
        ochn[2] = (UART_Buffer[6] >>6) & 0x1;

    
        rx0[0] = (UART_Buffer[7]/100)<< 1;
        rx0[1] = (UART_Buffer[7]%100/10)<< 1;
        rx0[2] = (UART_Buffer[7]%100%10) << 1;

        rx1[0] = (UART_Buffer[8]/100) << 1;
        rx1[1] = (UART_Buffer[8]%100/10) << 1;
        rx1[2] = (UART_Buffer[8]%100%10) << 1;

        rx2[0] = (UART_Buffer[9]/100)<< 1;
        rx2[1] = (UART_Buffer[9]%100/10) << 1;
        rx2[2] = (UART_Buffer[9]%100%10) << 1;

        rx3[0] = (UART_Buffer[10]/100) << 1;
        rx3[1] = (UART_Buffer[10]%100/10) << 1;
        rx3[2] = (UART_Buffer[10]%100%10) << 1;
    }
}


void set_window_data(void)
{
		cur_index = UART_Buffer[1];
    mode = UART_Buffer[2];
}

void config_window_data(void)
{
		cur_index = UART_Buffer[1];

    mode = UART_Buffer[2];
    rates = (UART_Buffer[3] << 8) + UART_Buffer[4];
    rate[0] = (rates/1000)<< 1;
    rate[1] = (rates%1000/100) << 1;
    rate[2] = (rates%1000%100/10) << 1;
    rate[3] = (rates%1000%100%10) << 1;

    rates_yaw = (UART_Buffer[5] << 8) + UART_Buffer[6];
    rate_yaw[0] = (rates_yaw/1000) << 1;
    rate_yaw[1] = (rates_yaw%1000/100) << 1;
    rate_yaw[2] = (rates_yaw%1000%100/10) << 1;
    rate_yaw[3] = (rates_yaw%1000%100%10) << 1;

    acc_cali = UART_Buffer[7];

    rx_index = UART_Buffer[8];

    rgb_led = UART_Buffer[9];
}



void layout_window_data(void)
{
	cur_index = UART_Buffer[1];

  rx_show = UART_Buffer[2];
    
  mode_show = UART_Buffer[3];
    
  vol_show = UART_Buffer[4];
}


void vtx_window_data(void)
{
	  cur_index = UART_Buffer[1];

    chn[0] = (UART_Buffer[2] )<< 1;
    chn[1] = (UART_Buffer[3] )<< 1;
    chn[2] = (UART_Buffer[4] )<< 1;
    chn[3] = (UART_Buffer[5] )<< 1;

    ochn[0] = (UART_Buffer[6] )<< 1;
    ochn[1] = (UART_Buffer[7] )<< 1;
    ochn[2] = (UART_Buffer[8] )<< 1;
    ochn[3] = (UART_Buffer[9] )<< 1;
    
    band_index = UART_Buffer[10];
    vtx_index = UART_Buffer[11]<<1;

}

void main (void)
{
    enter_DefaultMode_from_RESET();

    IE_EA = 1;
    delayS(250);
//    

    while(1)
    {
//        if((UART_Buffer[0] & 0x0f) == 0x0f)
//				{
//					if(UART_Buffer[12] == OSD_checksum(UART_Buffer))
//					{
//            showcase = (UART_Buffer[0]>>4) & 0x0f;
//            switch (showcase) {
//            case 0:
//                flight_window_data();
//                break;

//            case 1:
//                set_window_data();
//                break;

//            case 2:
//                config_window_data();
//                break;

//            case 3:
//                layout_window_data();
//                break;

//            case 4:
//                vtx_window_data();
//                break;
//            }
//					}
//        }
    }
}

















