#include <SI_EFM8BB2_Register_Enums.h>
#include "ascii.h"
unsigned int line = 0;
SI_SBIT (LED_GREEN, SFR_P1, 4);                         // green LED

char *Buf;
int flag = 0;
int temp =0;

extern unsigned char lock;
extern unsigned char flymode;
extern unsigned char HORIZON;

unsigned char LiteText[] = {'L','I','T','E','S'};

unsigned char voltage[] = {'V','O','L'};
unsigned char VOT_value[5] = {0,0,0};

unsigned char lockText[] = {'L','O','C','K'};

unsigned char flymodeText[] = {'A','C','R','0','N','G','L','E','H','I','Z'};


unsigned char timeText[] = {'T','I','M','E'};

unsigned char buffer[20];
unsigned int buffer1[10];

unsigned short minute=0,second=0;
unsigned char min_text[2];
unsigned char sec_text[2];
unsigned short rising_count=0;                        //上升沿中断次数统计
void delay(int n)
{
	int i;
	for(i=0;i<n;i++);
}
void OSD_OUT(char buf)
{
	int i;
	SPI0DAT = buf;
	for(i=0;i<1;i++);
}


SI_INTERRUPT (INT0_ISR, INT0_IRQn)
{
	 if(flag == 0)
	 {
		  TH0 = 0x00;
		  TL0 = 0x00;
		  IT01CF = IT01CF_IN0PL__ACTIVE_LOW | IT01CF_IN0SL__P0_2;            //切换为下降沿中断触发
			if(lock == 0x01)    /*检测到飞控解锁 开始计时*/
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
		  if(((TH0<<8)|TL0)>490)
  		{				
				 line = 0;
			}
			if(130 < line && line < 147)
			{
					temp = line - 130;
					delay(63);
					OSD_OUT(LargeNumbers[320+(2*temp)]);
					OSD_OUT(LargeNumbers[320+(2*temp)+1]);
			}
			
			
			if(200 < line && line < 209)    //判断到啊200行
			{	
				  /*飞行模式显示*/
				 //flymodeText[] = {'A','C','R','0','N','G','L','E','H','I','Z'};
					temp = line - 201; 
				if( flymode == 0x00 && HORIZON == 0x00 )   //自稳模式
				{
					buffer[0]=(flymodeText[0])<<3; 	
					buffer[1]=(flymodeText[4])<<3; 	
					buffer[2]=(flymodeText[5])<<3; 	
					buffer[3]=(flymodeText[6])<<3;	
					buffer[4]=(flymodeText[7])<<3;	
					
					delay(106);
					OSD_OUT(letters[(buffer[0])+(temp)]);
					OSD_OUT(letters[(buffer[1])+(temp)]);
					OSD_OUT(letters[(buffer[2])+(temp)]);		
					OSD_OUT(letters[(buffer[3])+(temp)]);
					OSD_OUT(letters[(buffer[4])+(temp)]);
					
				}else if( flymode == 0x01 && HORIZON== 0x00 )    //手动模式
				{
					buffer[0]=(flymodeText[0])<<3; 	
					buffer[1]=(flymodeText[1])<<3; 	
					buffer[2]=(flymodeText[2])<<3; 	
					buffer[3]=(flymodeText[3])<<3;	

					delay(106);
					OSD_OUT(letters[(buffer[0])+(temp)]);
					OSD_OUT(letters[(buffer[1])+(temp)]);
					OSD_OUT(letters[(buffer[2])+(temp)]);		
					OSD_OUT(letters[(buffer[3])+(temp)]);
				}
				else if( HORIZON == 0x01 ){						//半自稳模式
					buffer[0]=(flymodeText[8])<<3; 	
					buffer[1]=(flymodeText[3])<<3; 	
					buffer[2]=(flymodeText[2])<<3; 
					buffer[3]=(flymodeText[9])<<3;	
					buffer[4]=(flymodeText[10])<<3;	
					buffer[5]=(flymodeText[3])<<3;	
					buffer[6]=(flymodeText[4])<<3;	
					
					delay(103);
					OSD_OUT(letters[(buffer[0])+(temp)]);
					OSD_OUT(letters[(buffer[1])+(temp)]);
					OSD_OUT(letters[(buffer[2])+(temp)]);		
					OSD_OUT(letters[(buffer[3])+(temp)]);
					OSD_OUT(letters[(buffer[4])+(temp)]);
					OSD_OUT(letters[(buffer[5])+(temp)]);
					OSD_OUT(letters[(buffer[6])+(temp)]);	
				}	
				
			}
			
			if(210 < line && line < 219)    //判断到啊200行
			{	
				  /*lock显示*/
					temp = line - 211; 
					
				if(lock == 0x00)    /*检测到飞控未解锁*/
				{
					buffer[0]=(lockText[0])<<3; 	
					buffer[1]=(lockText[1])<<3; 	
					buffer[2]=(lockText[2])<<3; 	
					buffer[3]=(lockText[3])<<3;	
					buffer[4]=(lockText[4])<<3;	
				
					delay(57);
					OSD_OUT(letters[(buffer[0])+(temp)]);
					OSD_OUT(letters[(buffer[1])+(temp)]);
					OSD_OUT(letters[(buffer[2])+(temp)]);		
					OSD_OUT(letters[(buffer[3])+(temp)]);
					
				}	
			}
			if(220 < line && line < 229)    //判断到啊200行
			{	
					temp = line - 221; 				
				if(lock == 0x00)    /*检测到飞控未解锁*/
				{
					/*Lite 2S显示*/
					buffer[11]=(LiteText[0])<<3;
					buffer[12]=(LiteText[1])<<3;   
					buffer[13]=(LiteText[2])<<3; 	
					buffer[14]=(LiteText[3])<<3; 	
					buffer[15]=(LiteText[4])<<3; 

					delay(53);
					OSD_OUT(letters[(buffer[11])+(temp)]);
					OSD_OUT(letters[(buffer[12])+(temp)]);
					OSD_OUT(letters[(buffer[13])+(temp)]);
					OSD_OUT(letters[(buffer[14])+(temp)]);
					delay(2);
					OSD_OUT(numbers[16+(temp)]);
					OSD_OUT(letters[(buffer[15])+(temp)]);	
				}	
			}
			
			
			if(230 < line && line < 239)                              //判断到啊230行
			{
				
				  /*电压字符和时间字符显示*/
					temp = line - 231;
					buffer[0]=(voltage[0])<<3;
					buffer[1]=(voltage[1])<<3;
					buffer[2]=(voltage[2])<<3;   
					
					buffer[7]=(timeText[0])<<3; 	
					buffer[8]=(timeText[1])<<3; 	
					buffer[9]=(timeText[2])<<3; 	
					buffer[10]=(timeText[3])<<3; 
					
					delay(3);
					OSD_OUT(letters[(buffer[0])+(temp)]);
					OSD_OUT(letters[(buffer[1])+(temp)]);
					OSD_OUT(letters[(buffer[2])+(temp)]);	
					
					delay(93);
					OSD_OUT(letters[(buffer[7])+(temp)]);
					OSD_OUT(letters[(buffer[8])+(temp)]);
					OSD_OUT(letters[(buffer[9])+(temp)]);
					OSD_OUT(letters[(buffer[10])+(temp)]);
			}
		
			
			if(240 < line && line < 249)                      //判断到达240行
			{
				  /*电压数值 和 时间值显示  VOT_value数值来源于飞控通过SPI传输*/
					temp = line - 241;
					buffer1[0]=VOT_value[0]<<3; 
					buffer1[1]=VOT_value[1]<<3; 
					buffer1[2]=VOT_value[2]<<3; 
				 /*min_text sec_text 数据来源于模拟时间*/
					buffer1[3]=min_text[0]<<3; 
				  buffer1[4]=min_text[1]<<3; 
					buffer1[5]=sec_text[0]<<3; 
					buffer1[6]=sec_text[1]<<3; 
				
					delay(0);				
					OSD_OUT(numbers[(buffer1[0])+(temp)]);
					OSD_OUT(numbers[88+(temp)]);
					OSD_OUT(numbers[(buffer1[1])+(temp)]);
					OSD_OUT(numbers[(buffer1[2])+(temp)]);
				  
				  delay(91);
				  OSD_OUT(numbers[(buffer1[3])+(temp)]);
					OSD_OUT(numbers[(buffer1[4])+(temp)]);
				  OSD_OUT(numbers[104+(temp)]);
					OSD_OUT(numbers[(buffer1[5])+(temp)]);
				  OSD_OUT(numbers[(buffer1[6])+(temp)]);
				

			}
			
			OSD_OUT(0x00);
			line++;
		  IT01CF = IT01CF_IN0PL__ACTIVE_HIGH | IT01CF_IN0SL__P0_2;                     //切换为上升沿中断触发
		  flag = 0;
	 } 
}


