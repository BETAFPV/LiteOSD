#include "show.h"
#include "ascii.h"



unsigned short rx0_l=70;
unsigned short rx1_l=85;
unsigned short rx2_l=105;
unsigned short lock_l=150;
unsigned short rxloss_l=185;
unsigned short low_bat_l=200;
unsigned short mode_l=220;
unsigned short vol_l=235;

unsigned char  temp = 0;

extern unsigned short line;
extern unsigned char  VOT_value[3];
extern unsigned char  min_text[2];
extern unsigned char  sec_text[2];
extern unsigned char  rx_index ;
extern unsigned char  flymode ;
extern unsigned char   rx0[3];
extern unsigned char   rx1[3];
extern unsigned char   rx2[3];
extern unsigned char   rx3[3];
extern unsigned char   chn[4];


void delay(unsigned char n)
{
    unsigned char i;
    for(i=0; i<n; i++)
        ;
}


void flight_window(unsigned short line)
{
	if(rx0_l<line && line<rx0_l+9) {
		temp = line - rx0_l;
		if(1)
		{
				delay(3);
				SPI0DAT = letters[_r+(temp)];
				SPI0DAT = letters[0+(temp)];
				SPI0DAT =numbers[rx0[0]+(temp)];
				SPI0DAT =numbers[88+(temp)];
				SPI0DAT =numbers[rx0[1]+(temp)];
				delay(1);
				SPI0DAT =numbers[rx0[2]+(temp)];
				
				delay(3);
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[0+(temp)];
				delay(3);
				SPI0DAT = letters[_p+(temp)];
				delay(5);
				SPI0DAT = letters[0+(temp)];
				delay(5);
				SPI0DAT =numbers[rx1[0]+(temp)];
				delay(4);
				SPI0DAT =numbers[88+(temp)];
				delay(5);
				SPI0DAT =numbers[rx1[1]+(temp)];
				delay(6);
				SPI0DAT =numbers[rx1[2]+(temp)];
		}
	}
	if(rx1_l<line && line<rx1_l+9) {
		temp = line - rx1_l;
		if(1)
		{
				delay(1);
				SPI0DAT = letters[_y+(temp)];
				SPI0DAT = letters[0+(temp)];
				SPI0DAT =numbers[rx2[0]+(temp)];
				SPI0DAT =numbers[88+(temp)];
				SPI0DAT =numbers[rx2[1]+(temp)];
				delay(1);
				SPI0DAT =numbers[rx2[2]+(temp)];
			
				delay(3);
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[0+(temp)];
				delay(3);
				SPI0DAT = letters[_t+(temp)];
				delay(5);
				SPI0DAT = letters[0+(temp)];
				delay(5);
				SPI0DAT =numbers[rx3[0]+(temp)];
				delay(4);
				SPI0DAT =numbers[88+(temp)];
				delay(5);
				SPI0DAT =numbers[rx3[1]+(temp)];
				delay(6);
				SPI0DAT =numbers[rx3[2]+(temp)];
		}
	}
	if(rx2_l<line && line<rx2_l+9) {
		temp = line - rx2_l;
		if(1)
		{
				SPI0DAT = letters[_c+(temp)];
				SPI0DAT = letters[_h+(temp)];
			
				delay(5);
				SPI0DAT = letters[0+(temp)];
				SPI0DAT =numbers[chn[0]+(temp)];
				delay(4);
				SPI0DAT = letters[0+(temp)];
				SPI0DAT =numbers[chn[1]+(temp)];
				delay(5);
				SPI0DAT = letters[0+(temp)];	
				SPI0DAT =numbers[chn[2]+(temp)];
				delay(6);
				SPI0DAT = letters[0+(temp)];
				SPI0DAT =numbers[chn[3]+(temp)];
		}
	}
	if(lock_l<line && line<lock_l+9) {
		temp = line - lock_l;
		if(1)
		{
				delay(67);
				SPI0DAT = letters[_d+(temp)];
				SPI0DAT = letters[_i+(temp)];
				SPI0DAT = letters[_s+(temp)];
				SPI0DAT = letters[_a+(temp)];
				SPI0DAT = letters[_r+(temp)];
				delay(1);
				SPI0DAT = letters[ _m+(temp)];
		}
	}
	
	if(rxloss_l<line && line<rxloss_l+9) {
		temp = line - rxloss_l;
		if(1)
		{
				delay(65);
				SPI0DAT = letters[_r+(temp)];
				SPI0DAT = letters[_x+(temp)];
				SPI0DAT = letters[0+(temp)];
			
				SPI0DAT = letters[_l+(temp)];				
				SPI0DAT = letters[_o+(temp)];
				delay(1);
				SPI0DAT = letters[_s+(temp)];
				delay(4);
				SPI0DAT = letters[ _s+(temp)];
		}
	}
	
	if(low_bat_l<line && line<low_bat_l+9) {
		temp = line - low_bat_l;
		if(1)
		{
				delay(62);
				SPI0DAT = letters[_l+(temp)];
				SPI0DAT = letters[_o+(temp)];
				SPI0DAT = letters[_w+(temp)];
				SPI0DAT = letters[0+(temp)];
				SPI0DAT = letters[_v+(temp)];
				delay(1);
				SPI0DAT = letters[_o+(temp)];
				delay(4);
				SPI0DAT = letters[ _l+(temp)];
		}
	}
	
	if(mode_l<line && line<mode_l+9) {
			temp = line - mode_l;
			switch (rx_index) {
			case 0:
			case 1:
					SPI0DAT =letters[_b+(temp)];
					SPI0DAT =letters[_y+(temp)];
					delay(10);
					break;
			case 2:
					SPI0DAT =letters[_s+(temp)];
					SPI0DAT =letters[_b+(temp)];
					SPI0DAT =letters[_u+(temp)];
					SPI0DAT =letters[_s+(temp)];
					delay(2);
					break;
			case 3:
					SPI0DAT =letters[_d+(temp)];
					SPI0DAT =letters[_s+(temp)];
					SPI0DAT =letters[_m+(temp)];
					SPI0DAT =letters[_x+(temp)];
					delay(2);
					break;
			}
			switch (flymode) {
			case 0:
					delay(110);
					SPI0DAT =letters[_l+(temp)];
					SPI0DAT =letters[_e+(temp)];
					SPI0DAT =letters[_v+(temp)];
					SPI0DAT =letters[_e+(temp)];
					SPI0DAT =letters[_l+(temp)];
					break;
			case 1:
					delay(112);
					SPI0DAT =letters[_a+(temp)];
					SPI0DAT =letters[_c+(temp)];
					SPI0DAT =letters[_r+(temp)];
					SPI0DAT =letters[_o+(temp)];
					break;
			case 2:
					delay(110);
					SPI0DAT =letters[_r+(temp)];
					SPI0DAT =letters[_a+(temp)];
					SPI0DAT =letters[_c+(temp)];
					SPI0DAT =letters[_e+(temp)];
					delay(1);
					SPI0DAT =numbers[144+(temp)];
					SPI0DAT =letters[_h+(temp)];
					break;
			case 3:
					delay(110);
					SPI0DAT =letters[_r+(temp)];
					SPI0DAT =letters[_a+(temp)];
					SPI0DAT =letters[_c+(temp)];
					SPI0DAT =letters[_e+(temp)];
					delay(1);
					SPI0DAT =numbers[144+(temp)];
					SPI0DAT =letters[_a+(temp)];
					break;
			case 4:
					delay(110);
					SPI0DAT =letters[_h+(temp)];
					SPI0DAT =letters[_o+(temp)];
					SPI0DAT =letters[_r+(temp)];
					SPI0DAT =letters[_i+(temp)];
					SPI0DAT =letters[_z+(temp)];
					delay(1);
					SPI0DAT =letters[_o+(temp)];
					delay(3);
					SPI0DAT =letters[_n+(temp)];
					break;
			}

	}
		
	if(vol_l<line && line<vol_l+9) {
			temp = line - vol_l;
			SPI0DAT =letters[ _v+(temp)];
			SPI0DAT =numbers[VOT_value[0]+(temp)];
			SPI0DAT =numbers[88+(temp)];
			SPI0DAT =numbers[VOT_value[1]+(temp)];
			SPI0DAT =numbers[VOT_value[2]+(temp)];

			delay(120);
			SPI0DAT =numbers[ min_text[0]+(temp)];
			SPI0DAT =numbers[ min_text[1]+(temp)];
			SPI0DAT =numbers[104+(temp)];
			SPI0DAT =numbers[ sec_text[0]+(temp)];
			SPI0DAT =numbers[ sec_text[1]+(temp)];
    }

}


void set_window(unsigned short line)
{



}



void config_window(unsigned short line)
{




}


void layout_window(unsigned short line)
{




}


void vtx_window(unsigned short line)
{



}




