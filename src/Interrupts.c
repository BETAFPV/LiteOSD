#include <SI_EFM8BB2_Register_Enums.h>
#include "ascii.h"

//SI_SBIT (LED_GREEN, SFR_P0, 6);                         // green LED

char *Buf;
int flag = 0;
int temp =0,temp1=0,temp2=0;
unsigned int time = 0;
unsigned int line = 0;
unsigned char lock = 0;
unsigned char flymode = 0;
unsigned char m1=0;
unsigned char m2=0;
unsigned char m3=0;
unsigned char m4=0;

unsigned char  kp[9] = {0};
unsigned char  ki[9] = {0};
unsigned char  kd[9] = {0};

unsigned char VOT_value[3] = {0,0,0};
unsigned char state_value[3] = {0,0,0};
unsigned char moto_value[4] = {0,0,0,0};
unsigned char  buffer[10];
unsigned int   buffer1[10];

unsigned char flight_window=0;  //0:flight   1:set memu window 
unsigned char osd_class=0;  // 0:main 1:pid  2:moto 3:save  4:exit
unsigned char proto=1;
unsigned char index=0;   

unsigned short minute=0,second=0;
unsigned char min_text[2];
unsigned char sec_text[2];
unsigned short rising_count=0;                        //上升沿中断次数统计
void delay(int n)
{
	int i;
	for(i=0;i<n;i++);
}

void delay_us()
{
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}

SI_INTERRUPT (INT0_ISR, INT0_IRQn)
{	 		
	 IE_EX0 = 0;
	 if(flag == 0)
	 { 
			TH0 = 0x00;
			TL0 = 0x00;
		  IT01CF = IT01CF_IN0PL__ACTIVE_LOW | IT01CF_IN0SL__P0_2;            //切换为下降沿中断触发
			if(lock == 1)
			{
					rising_count++;
			}

			/*模拟分/秒*/
			if(rising_count>=16129)         //使用视频的同步信号模拟一个粗虐延时 16129次中断大概时间为1S定时
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
			}
		  flag = 1;
	 }
	 else 
	 {
			if((TH0<<8 | TL0) > 490)
			{				
				line = 0;
			}
			if(flight_window == 1)     //如果flight_window == 1 设置界面
			{
				if(osd_class == 0)
				{
					if(100 < line && line < 109)
					{
							temp = line - 101;
							delay(30);
							SPI0DAT = numbers[80+(temp)];
							delay_us();
							SPI0DAT = U_letters[_m+(temp)];
							delay_us();
							SPI0DAT = U_letters[_e+(temp)];
							delay_us();
							SPI0DAT = U_letters[_m+(temp)];	
							delay_us();
							SPI0DAT = U_letters[_u+(temp)];
							delay_us();
							SPI0DAT = numbers[80+(temp)];
					}
					if(120 < line && line < 129)
					{
							temp = line - 121;
							if (index == 0){
								delay(36);
								SPI0DAT = numbers[ 96+(temp)];
								delay_us();
							}else{
								delay(38);
							}
							SPI0DAT = U_letters[0+(temp)];
							delay_us();
							SPI0DAT = U_letters[_p+(temp)];
							delay_us();
							SPI0DAT = U_letters[_i+(temp)];
							delay_us();
							SPI0DAT = U_letters[_d+(temp)];	
							delay(41);
							SPI0DAT = numbers[ 96+(temp)];
					}
					if(135 < line && line < 145)
					{
							temp = line - 136;
							if (index == 1){
								delay(35);
								SPI0DAT = numbers[ 96+(temp)];
								delay_us();
							}else{
								delay(37);
							}
							SPI0DAT = U_letters[0+(temp)];
							delay_us();
							SPI0DAT = U_letters[_m+(temp)];
							delay_us();
							SPI0DAT = U_letters[_o+(temp)];
							delay_us();
							SPI0DAT = U_letters[_t+(temp)];
							delay_us();
							SPI0DAT = U_letters[_o+(temp)];	
							delay(39);
							SPI0DAT = numbers[ 96+(temp)];
					}
					if(150 < line && line < 159)
					{
							temp = line - 151;
							if (index == 2)
							{
									delay(34);
									SPI0DAT = numbers[ 96+(temp)];
									delay_us();
							}
							else
							{
									delay(36);
							}
							SPI0DAT = U_letters[0+(temp)];
							delay_us();
							SPI0DAT = U_letters[_s+(temp)];
							delay_us();
							SPI0DAT = U_letters[_a+(temp)];
							delay_us();
							SPI0DAT = U_letters[_v+(temp)];
							delay_us();
							SPI0DAT = U_letters[_e+(temp)];	
					}
					if(165 < line && line < 175)
					{
							temp = line - 166;
							if (index == 3)
							{
									delay(33);
									SPI0DAT = numbers[ 96+(temp)];
									delay_us();
							}
							else
							{
									delay(35);
							}
							SPI0DAT = U_letters[0+(temp)];
							delay_us();
							SPI0DAT = U_letters[_e+(temp)];
							delay_us();
							SPI0DAT = U_letters[_x+(temp)];
							delay_us();
							SPI0DAT = U_letters[_i+(temp)];
							delay_us();
							SPI0DAT = U_letters[_t+(temp)];
					}
				}
				if(osd_class == 1)
				{
						if(70 < line && line < 79)
						{
								temp = line - 71;
								delay(30);
								SPI0DAT = numbers[80+(temp)];
								delay_us();
								SPI0DAT = U_letters[_p+(temp)];
								delay_us();
								SPI0DAT = U_letters[_i+(temp)];
								delay_us();
								SPI0DAT = U_letters[_d+(temp)];	
								delay_us();
								SPI0DAT = numbers[80+(temp)];
						}
						if(80 < line && line < 89)
						{
								temp = line - 81;
								delay(60);
								SPI0DAT = U_letters[_r+(temp)];
								delay(12);
								SPI0DAT = U_letters[_p+(temp)];
								delay(12);
								SPI0DAT = U_letters[_y+(temp)];	
						}
						if(100 < line && line < 109)
						{
								temp = line - 101;
								if (index == 0 | index == 1 | index == 2)
								{
										delay(40);
										SPI0DAT = numbers[ 96+(temp)];
										delay_us();
								}
					 			else
								{
										delay(42);
								}
								SPI0DAT = U_letters[0+(temp)];
								delay_us();
								SPI0DAT = U_letters[_k+(temp)];	
								delay_us();								
								SPI0DAT = U_letters[_p+(temp)];			
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = numbers[kp[0]+(temp)];
								delay_us();
								SPI0DAT = numbers[88+(temp)];
								delay_us();
								SPI0DAT = numbers[kp[1]+(temp)];
								delay_us();
								SPI0DAT = numbers[kp[2]+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = numbers[kp[3]+(temp)];
								delay_us();
								SPI0DAT = numbers[88+(temp)];
								delay_us();
								SPI0DAT = numbers[kp[4]+(temp)];
								delay_us();
								SPI0DAT = numbers[kp[5]+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = numbers[kp[6]+(temp)];
								delay(1);
								SPI0DAT = numbers[88+(temp)];
								delay_us();
								SPI0DAT = numbers[kp[7]+(temp)];
								delay_us();
								SPI0DAT = numbers[kp[8]+(temp)];
								
						}
						if(110 < line && line < 119)
						{
								temp = line - 111;
								if ( index == 0)
								{
										delay(57);
										SPI0DAT = numbers[ 120+(temp)];
								}
								if ( index == 1)
								{
										delay(73);
										SPI0DAT = numbers[ 120+(temp)];
								}
								if ( index == 2)
								{
										delay(85);
										SPI0DAT = numbers[ 120+(temp)];
								}
						}
						if(130 < line && line < 139)
						{
								temp = line - 131;
								if (index == 3 | index == 4 | index == 5)
								{
										delay(39);
										SPI0DAT = numbers[ 96+(temp)];
										delay_us();
								}
								else
								{
										delay(41);
								}
								SPI0DAT = U_letters[0+(temp)];
								delay_us();
								SPI0DAT = U_letters[_k+(temp)];	
								delay_us();								
								SPI0DAT = U_letters[_i+(temp)];			
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = numbers[ki[0]+(temp)];
								delay_us();
								SPI0DAT = numbers[88+(temp)];
								delay_us();
								SPI0DAT = numbers[ki[1]+(temp)];
								delay_us();
								SPI0DAT = numbers[ki[2]+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = numbers[ki[3]+(temp)];
								delay_us();
								SPI0DAT = numbers[88+(temp)];
								delay_us();
								SPI0DAT = numbers[ki[4]+(temp)];
								delay_us();
								SPI0DAT = numbers[ki[5]+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = numbers[ki[6]+(temp)];
								delay(1);
								SPI0DAT = numbers[88+(temp)];
								delay_us();
								SPI0DAT = numbers[ki[7]+(temp)];
								delay_us();
								SPI0DAT = numbers[ki[8]+(temp)];								
								
						}
						if(140 < line && line < 149)
						{
								temp = line - 141;
								if ( index == 3)
								{
										delay(57);
										SPI0DAT = numbers[ 120+(temp)];
								}
								if ( index == 4)
								{
										delay(73);
										SPI0DAT = numbers[ 120+(temp)];
								}
								if ( index == 5)
								{
										delay(85);
										SPI0DAT = numbers[ 120+(temp)];
								}
						}
						if(160 < line && line < 169)
						{
								temp = line - 161;
								if (index == 6 | index == 7 | index == 8)
								{
										delay(38);
										SPI0DAT = numbers[ 96+(temp)];
								}
								else
								{
										delay(40);
								}
								SPI0DAT = U_letters[0+(temp)];
								delay_us();
								SPI0DAT = U_letters[_k+(temp)];	
								delay_us();								
								SPI0DAT = U_letters[_d+(temp)];			
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = numbers[kd[0]+(temp)];
								delay_us();
								SPI0DAT = numbers[88+(temp)];
								delay_us();
								SPI0DAT = numbers[kd[1]+(temp)];
								delay_us();
								SPI0DAT = numbers[kd[2]+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = numbers[kd[3]+(temp)];
								delay_us();
								SPI0DAT = numbers[88+(temp)];
								delay_us();
								SPI0DAT = numbers[kd[4]+(temp)];
								delay_us();
								SPI0DAT = numbers[kd[5]+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = numbers[kd[6]+(temp)];
								delay(1);
								SPI0DAT = numbers[88+(temp)];
								delay_us();
								SPI0DAT = numbers[kd[7]+(temp)];
								delay_us();
								SPI0DAT = numbers[kd[8]+(temp)];								
								
						}
						if(170 < line && line < 179)
						{
								temp = line - 171;
								if ( index == 6)
								{
										delay(57);
										SPI0DAT = numbers[ 120+(temp)];
								}
								if ( index == 7)
								{
										delay(73);
										SPI0DAT = numbers[ 120+(temp)];
								}
								if ( index == 8)
								{
										delay(85);
										SPI0DAT = numbers[ 120+(temp)];
								}
						}
						if(190 < line && line < 199)
						{
								temp = line - 191;
								if (index == 9)
								{
										delay(37);
										SPI0DAT = numbers[ 96+(temp)];
								}
								else
								{
										delay(39);
								}
								SPI0DAT = U_letters[0+(temp)];
								delay_us();						
								SPI0DAT = U_letters[_e+(temp)];
								delay_us();
								SPI0DAT = U_letters[_x+(temp)];
								delay_us();
								SPI0DAT = U_letters[_i+(temp)];
								delay_us();
								SPI0DAT = U_letters[_t+(temp)];	
								delay_us();
						}
				}
				if(osd_class == 2)
				{
						if(80 < line && line < 89)
						{
								temp = line - 81;
								delay(30);
								SPI0DAT = numbers[80+(temp)];
								delay_us();
								SPI0DAT = U_letters[_m+(temp)];
								delay_us();
								SPI0DAT = U_letters[_o+(temp)];
								delay_us();
								SPI0DAT = U_letters[_t+(temp)];	
								delay_us();
								SPI0DAT = U_letters[_o+(temp)];
								delay_us();
								SPI0DAT = U_letters[_r+(temp)];	
								delay_us();							
								SPI0DAT = numbers[80+(temp)];
						}
					
						if(100 < line && line < 109)
						{
								temp = line - 101;
								if (index == 0)
								{
										delay(40);
										SPI0DAT = numbers[ 96+(temp)];
								}
								else
								{
										delay(42);
								}
								SPI0DAT = U_letters[0+(temp)];
								delay_us();								
								SPI0DAT = U_letters[_m+(temp)];
								delay_us();
								SPI0DAT = numbers[ 8+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ (m1?_n:_d)+(temp)];
						}
						if(115 < line && line < 125)
						{
								temp = line - 116;
								if (index == 1)
								{
										delay(39);
										SPI0DAT = numbers[ 96+(temp)];
								}
								else
								{
										delay(41);
								}
								SPI0DAT = U_letters[0+(temp)];
								delay_us();								
								SPI0DAT = U_letters[_m+(temp)];
								delay_us();
								SPI0DAT = numbers[ 16+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ (m2?_n:_d)+(temp)];
						}
						
						if(130 < line && line < 139)
						{
								temp = line - 131;
								if (index == 2)
								{
										delay(38);
										SPI0DAT = numbers[ 96+(temp)];
								}
								else
								{
										delay(40);
								}
								SPI0DAT = U_letters[0+(temp)];
								delay_us();								
								SPI0DAT = U_letters[_m+(temp)];
								delay_us();
								SPI0DAT = numbers[ 24+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ (m3?_n:_d)+(temp)];
						}
						
						if(145 < line && line < 155)
						{
								temp = line - 146;
								if (index == 3)
								{
										delay(37);
										SPI0DAT = numbers[ 96+(temp)];
								}
								else
								{
										delay(39);
								}
								SPI0DAT = U_letters[0+(temp)];
								delay_us();								
								SPI0DAT = U_letters[_m+(temp)];
								delay_us();
								SPI0DAT = numbers[ 32+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ 0+(temp)];
								delay_us();
								SPI0DAT = U_letters[ (m4?_n:_d)+(temp)];		
						}
						if(165 < line && line < 175)
						{
								temp = line - 166;
								if (index == 4)
								{
										delay(36);
										SPI0DAT = numbers[ 96+(temp)];
								}
								else
								{
										delay(38);
								}
								SPI0DAT = U_letters[0+(temp)];
								delay_us();								
								SPI0DAT = U_letters[_e+(temp)];
								delay_us();
								SPI0DAT = U_letters[_x+(temp)];
								delay_us();
								SPI0DAT = U_letters[_i+(temp)];	
								delay_us();
								SPI0DAT = U_letters[_t+(temp)];
						}
					}
			}
			else//如果flight_window == 0 飞行界面
			{
					if(VOT_value[0] != 0)
					{
							if(125 < line && line < 135)
							{
									temp = line - 126;
									delay(60);
									SPI0DAT =numbers[80+(temp)];
									delay_us();
									SPI0DAT =numbers[112+(temp)];
									delay_us();
									SPI0DAT =numbers[80+(temp)];
							}
							
							if(170 < line && line < 179)
							{
									temp = line - 171;
									if(lock == 0)
									{
											delay(52);
											SPI0DAT = U_letters[_d+(temp)];
											delay_us();
											SPI0DAT = U_letters[_i+(temp)];
											delay_us();
											SPI0DAT = U_letters[_s+(temp)];	
											delay_us();
											SPI0DAT = U_letters[_a+(temp)];
											delay_us();
											SPI0DAT = U_letters[_r+(temp)];
											delay_us();
											SPI0DAT = U_letters[ _m+(temp)];
											delay_us();
											SPI0DAT = U_letters[ _i+(temp)];
											delay_us();
											SPI0DAT = U_letters[_n+(temp)];
											delay_us();
											SPI0DAT = U_letters[ _g+(temp)];
											delay_us();
											temp1 = minute*60 + second;
									}
									else 
									{		temp2 = minute*60 + second;
											if(temp1 + 2 > temp2)	
											{												
													delay(55);
													SPI0DAT =U_letters[_a+(temp)];
													SPI0DAT =U_letters[_r+(temp)];
													SPI0DAT =U_letters[_m+(temp)];
													SPI0DAT =U_letters[_i+(temp)];
													SPI0DAT =U_letters[_n+(temp)];
													SPI0DAT =U_letters[_g+(temp)];
											}
									}
							}
							if(210 < line && line < 219)
							{
									temp = line - 211;
									if(proto == 0)
									{
										delay(6);
										SPI0DAT =numbers[80+(temp)];
										delay_us();
										SPI0DAT =numbers[80+(temp)];
										delay_us();
										SPI0DAT =numbers[80+(temp)];
										delay_us();
									}
									
									if(proto == 1)
									{
											delay(4);
											SPI0DAT =U_letters[_b+(temp)];
											delay_us();
											SPI0DAT =U_letters[_a+(temp)];
											delay_us();
											SPI0DAT =U_letters[_y+(temp)];
											delay_us();
											SPI0DAT =U_letters[_a+(temp)];
											delay_us();
											SPI0DAT =U_letters[_n+(temp)];
											delay_us();
											SPI0DAT =U_letters[_g+(temp)];
									}	
									if(proto == 2)
									{
											delay(4);
											SPI0DAT =U_letters[_s+(temp)];
											delay_us();
											SPI0DAT =U_letters[_b+(temp)];
											delay_us();
											SPI0DAT =U_letters[_u+(temp)];
											delay_us();
											SPI0DAT =U_letters[_s+(temp)];
											delay(2);
									}
									if(proto == 3)
									{
											delay(4);
											SPI0DAT =U_letters[_d+(temp)];
											delay_us();
											SPI0DAT =U_letters[_s+(temp)];
											delay_us();
											SPI0DAT =U_letters[_m+(temp)];
											delay_us();
											SPI0DAT =U_letters[_x+(temp)];
											delay(2);
									}
									if(flymode == 0x00)
									{
											delay(84);
											SPI0DAT =U_letters[_l+(temp)];
											delay_us();
											SPI0DAT =U_letters[_e+(temp)];
											delay_us();
											SPI0DAT =U_letters[_v+(temp)];
											delay_us();
											SPI0DAT =U_letters[_e+(temp)];
											delay_us();
											SPI0DAT =U_letters[_l+(temp)];
									}	
									if(flymode == 0x01)
									{
											delay(83);
											SPI0DAT =U_letters[_a+(temp)];
											delay_us();
											SPI0DAT =U_letters[_c+(temp)];
											delay_us();
											SPI0DAT =U_letters[_r+(temp)];
											delay_us();
											SPI0DAT =U_letters[_o+(temp)];
									}
									if(flymode == 0x02)
									{
											delay(83);
											SPI0DAT =U_letters[_r+(temp)];
											delay_us();
											SPI0DAT =U_letters[_a+(temp)];
											delay_us();
											SPI0DAT =U_letters[_c+(temp)];
											delay_us();
											SPI0DAT =U_letters[_e+(temp)];
									}
									if(flymode == 0x03)
									{
											delay(83);
											SPI0DAT =U_letters[_h+(temp)];
											delay_us();
											SPI0DAT =U_letters[_o+(temp)];
											delay_us();
											SPI0DAT =U_letters[_r+(temp)];
											delay_us();
											SPI0DAT =U_letters[_i+(temp)];
											delay_us();
											SPI0DAT =U_letters[_z+(temp)];
											delay_us();
											SPI0DAT =U_letters[_o+(temp)];
											delay_us();
											SPI0DAT =U_letters[_n+(temp)];
									}
							}	
							if(220 < line && line < 229)
							{
									temp = line - 221;
									delay(4);
									SPI0DAT =U_letters[ _v+(temp)];
									SPI0DAT =U_letters[_o+(temp)];
									SPI0DAT =U_letters[_l+(temp)];	

									delay(90);
									SPI0DAT =U_letters[_t+(temp)];
									SPI0DAT =U_letters[_i+(temp)];
									SPI0DAT =U_letters[_m+(temp)];
									SPI0DAT =U_letters[_e+(temp)];
							}
							if(230 < line && line < 239)
							{
									temp = line - 231;
									delay(3);
									SPI0DAT =numbers[ VOT_value[0]+(temp)];
									SPI0DAT =numbers[88+(temp)];
									SPI0DAT =numbers[VOT_value[1]+(temp)];
									delay_us();
									SPI0DAT =numbers[VOT_value[2]+(temp)];
								
									delay(87);
									SPI0DAT =numbers[ min_text[0]+(temp)];
									SPI0DAT =numbers[ min_text[1]+(temp)];
									SPI0DAT =numbers[104+(temp)];
									SPI0DAT =numbers[ sec_text[0]+(temp)];
									SPI0DAT =numbers[ sec_text[1]+(temp)];
									
							}
					}
					else
					{
							if(145 < line && line < 155)
							{
									temp = line - 146;
									delay(55);
									SPI0DAT = U_letters[_l+(temp)];
									delay_us();
									SPI0DAT = U_letters[_o+(temp)];
									delay_us();
									SPI0DAT = U_letters[_a+(temp)];	
									delay_us();
									SPI0DAT = U_letters[_d+(temp)];
									delay_us();
									SPI0DAT = U_letters[_i+(temp)];
									delay_us();
									SPI0DAT = U_letters[ _n+(temp)];
									delay_us();
									SPI0DAT = U_letters[ _g+(temp)];
									delay_us();
							}				
					}
			}
			SPI0DAT = 0x00;
			line++;
			IT01CF = IT01CF_IN0PL__ACTIVE_HIGH | IT01CF_IN0SL__P0_2; 
			flag=0;
	}
	IE_EX0 = 1;
}

