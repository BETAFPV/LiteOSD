
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

unsigned short Vol;
unsigned short Cur;
unsigned char  min_text[2] = {0};
unsigned char  sec_text[2] = {0};
unsigned char  lock = 0;
unsigned char  showcase = 9;
unsigned char  VOT_value[3] = {0};
unsigned char  Cur_value[3] = {0};
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
unsigned char   rx0[3] = {0};
unsigned char   rx1[3] = {0};
unsigned char   rx2[3] = {0};
unsigned char   rx3[3] = {0};
unsigned char   chn[4] = {0};
unsigned char  turtle=0;
unsigned char  vtx_power =0;
unsigned char  channel = 0;
unsigned char  vtx_power_index =0;
unsigned char  channel_index = 0;
unsigned char main_version = 0;
unsigned char modify_version = 0;

unsigned short rates = 0;
unsigned short rates_yaw = 0;

unsigned char rate[4] = {0};
unsigned char rate_yaw[4] = {0};
unsigned char profileAB = 0;

unsigned short low_bat_l=160;
unsigned short mode_l=210;
unsigned short vol_l=220;
unsigned short curr_l=230;
unsigned short turtle_l=180;


unsigned char low_bat_l_temp[2]={0};
unsigned char mode_l_temp[2]={0};
unsigned char vol_l_temp[2]={0};
unsigned char curr_l_temp[2]={0};
unsigned char turtle_l_temp[2]={0};
unsigned char low_battery[2]={48,64};

extern unsigned char UART_Buffer[12];
extern void delay(unsigned char n);

uint8_t OSD_checksum(uint8_t UART_Buffer[])
{
    unsigned char i;
    unsigned char sum = 0;
    for (i = 0; i < 11;i++ )
    {
        sum += UART_Buffer[i];
    }
    return sum;
}

void rates_window_data()
{
    index = UART_Buffer[1];
    
    rates = (UART_Buffer[2] << 8) + UART_Buffer[3];
    rate[0] = (rates/1000) << 3;
    rate[1] = (rates%1000/100) << 3;
    rate[2] = (rates%1000%100/10) << 3;
    rate[3] = (rates%1000%100%10) << 3;
    
    rates_yaw = (UART_Buffer[4] << 8) + UART_Buffer[5];
    rate_yaw[0] = (rates_yaw/1000) << 3;
    rate_yaw[1] = (rates_yaw%1000/100) << 3;
    rate_yaw[2] = (rates_yaw%1000%100/10) << 3;
    rate_yaw[3] = (rates_yaw%1000%100%10) << 3;
    
    
    profileAB = UART_Buffer[6];
}

void display_window_data()
{
    index = UART_Buffer[1];
    
    low_bat_l = UART_Buffer[2] * 10;
    mode_l = UART_Buffer[3] *10 ;
    vol_l = UART_Buffer[4] *10 ;
    curr_l = UART_Buffer[5] * 10;
    turtle_l = UART_Buffer[6] * 10;
    
    low_bat_l_temp[0] = (UART_Buffer[2]/10) << 3;
    low_bat_l_temp[1] = (UART_Buffer[2]%10) << 3;
    
    mode_l_temp[0] = (UART_Buffer[3]/10) << 3;
    mode_l_temp[1] = (UART_Buffer[3]%10) << 3;
    
    vol_l_temp[0] = (UART_Buffer[4]/10) << 3;
    vol_l_temp[1] = (UART_Buffer[4]%10) << 3;
    
    curr_l_temp[0] = (UART_Buffer[5]/10) << 3;
    curr_l_temp[1] = (UART_Buffer[5]%10) << 3;
    
    turtle_l_temp[0] = (UART_Buffer[6]/10) << 3;
    turtle_l_temp[1] = (UART_Buffer[6]%10) << 3;

    low_battery[0] = (UART_Buffer[7]/10) << 3;
    low_battery[1] = (UART_Buffer[7]%10) << 3;
}

void flight_window_data()
{
	lock = UART_Buffer[1];

        
    Vol = (UART_Buffer[3] << 8) + UART_Buffer[4];
    VOT_value[0] = (Vol/100) << 3;
    VOT_value[1] = (Vol%100/10) << 3;
    VOT_value[2] = (Vol%100%10) << 3;

    proto = UART_Buffer[5];

    chn[1] = (UART_Buffer[6] >>0) & 0x1;
    chn[2] = (UART_Buffer[6] >>1) & 0x1;
    chn[3] = (UART_Buffer[6] >>2) & 0x1;

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

    turtle = UART_Buffer[7];
    
    Cur = (UART_Buffer[8] << 8) + UART_Buffer[9];
    Cur_value[0] = (Cur/100) << 3;
    Cur_value[1] = (Cur%100/10) << 3;
    Cur_value[2] = (Cur%100%10) << 3;
}
 
void set_window_data()
{
	index = UART_Buffer[1];
    main_version = UART_Buffer[2]<<3;
    modify_version = UART_Buffer[3]<<3;
}


void pid_window_data()
{
	index = UART_Buffer[1];


    kp[0] = (UART_Buffer[2]/100) << 3;
    kp[1] = (UART_Buffer[2]%100/10) << 3;
    kp[2] = (UART_Buffer[2]%100%10) << 3;
    kp[3] = (UART_Buffer[3]/100) << 3;
    kp[4] = (UART_Buffer[3]%100/10) << 3;
    kp[5] = (UART_Buffer[3]%100%10) << 3;
    kp[6] = (UART_Buffer[4]/100) << 3;
    kp[7] = (UART_Buffer[4]%100/10) << 3;
    kp[8] = (UART_Buffer[4]%100%10) << 3;

    ki[0] = (UART_Buffer[5]/100) << 3;
    ki[1] = (UART_Buffer[5]%100/10) << 3;
    ki[2] = (UART_Buffer[5]%100%10) << 3;
    ki[3] = (UART_Buffer[6]/100) << 3;
    ki[4] = (UART_Buffer[6]%100/10) << 3;
    ki[5] = (UART_Buffer[6]%100%10) << 3; 
    ki[6] = (UART_Buffer[7]/100) << 3;
    ki[7] = (UART_Buffer[7]%100/10) << 3;
    ki[8] = (UART_Buffer[7]%100%10) << 3;

    kd[0] = (UART_Buffer[8]/100) << 3;
    kd[1] = (UART_Buffer[8]%100/10) << 3;
    kd[2] = (UART_Buffer[8]%100%10) << 3;
    kd[3] = (UART_Buffer[9]/100) << 3;
    kd[4] = (UART_Buffer[9]%100/10) << 3;
    kd[5] = (UART_Buffer[9]%100%10) << 3;
    kd[6] = (UART_Buffer[10]/100) << 3;
    kd[7] = (UART_Buffer[10]%100/10) << 3;
    kd[8] = (UART_Buffer[10]%100%10) << 3;
}



void motor_window_data()
{
    index = UART_Buffer[1];

    m1 = ((UART_Buffer[2]>>0) & 0x01) << 3;
    m2 = ((UART_Buffer[2]>>1) & 0x01) << 3;
    m3 = ((UART_Buffer[2]>>2) & 0x01) << 3;
    m4 = ((UART_Buffer[2]>>3) & 0x01) << 3;
}


void receiver_window_data()
{
	index = UART_Buffer[1];
	

	rx0[0] = (UART_Buffer[2]/100) << 3;
    rx0[1] = (UART_Buffer[2]%100/10) << 3;
    rx0[2] = (UART_Buffer[2]%100%10) << 3;

    rx1[0] = (UART_Buffer[3]/100) << 3;
    rx1[1] = (UART_Buffer[3]%100/10) << 3;
    rx1[2] = (UART_Buffer[3]%100%10) << 3;
    
    rx2[0] = (UART_Buffer[4]/100) << 3;
    rx2[1] = (UART_Buffer[4]%100/10) << 3;
    rx2[2] = (UART_Buffer[4]%100%10) << 3;
    
    rx3[0] = (UART_Buffer[5]/100) << 3;
    rx3[1] = (UART_Buffer[5]%100/10) << 3;
    rx3[2] = (UART_Buffer[5]%100%10) << 3;
    
	chn[0] = (UART_Buffer[6] ) &0x1;
	chn[1] = (UART_Buffer[7] )&0x1;
	chn[2] = (UART_Buffer[8] )&0x1;
	chn[3] = (UART_Buffer[9] )&0x1;
}

void sa_window_data()
{
	index = UART_Buffer[1];
    
    channel = UART_Buffer[2];
    vtx_power = UART_Buffer[3];
    channel_index = UART_Buffer[5];
    vtx_power_index = UART_Buffer[6];
}



void delayS(unsigned char n)
{
	unsigned char i;
    unsigned int j;
	for(i=0;i<n;i++)
        for(j=500000;j>0;j--);
        
}

//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------
void main (void)
{
   enter_DefaultMode_from_RESET();

   IE_EA = 1;
//   delayS(250);
//   delayS(200);
   SPI0CKR = (3 << SPI0CKR_SPI0CKR__SHIFT);
    
    
   while(1)
   {
     if(UART_Buffer[11] == OSD_checksum(UART_Buffer))
     {
        showcase = (UART_Buffer[0]>>4) & 0x0f;
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
                break;
            case 6:
                display_window_data();
                break;
            case 7:
                rates_window_data();
                break;
            default:
                break;
        }
     }
   }
}
