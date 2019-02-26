//CLK  P1.2
//CSN  P1.3
//DATA P1.5
#include "spi.h"
#include <intrins.h>

/*粗虐微秒延时*/
void delay_us(unsigned char i)
{
		unsigned char n;
		for(n=0;n<i;i++)
		{
				_nop_();
				_nop_();
				_nop_();
				_nop_();
		}
}
/*********************************************
*函数名：spi_cson
*功  能：SPI 片选信号开启
*参  数：void
*返回值：void
**********************************************/
void spi_cson(void)
{
	CSN = 0;             //拉低片选脚
}


/*********************************************
*函数名：spi_cson
*功  能：SPI 片选信号关闭
*参  数：void
*返回值：void
**********************************************/
void spi_csoff(void)
{
	CSN = 1;             //拉高片选脚 
}


/*********************************************
*函数名：spi_sendbyte
*功  能：发送一个字节
*参  数：void
*返回值：void
**********************************************/
void spi_sendbyte(unsigned char dat)
{
		int i;
		for(i=7 ; i>=0 ; i--)
		{
				if((dat>>i)&1)
				{
							IO = 1;
				}
				else
				{
							IO = 0;
				}
				CLK = 1;
				delay_us(1);
				CLK = 0;
				delay_us(1);
		}
}


/*********************************************
*函数名：spi_recvbyte
*功  能：向spi MOSI接收一个字节
*参  数：void
*返回值：recv 接收到的字节
**********************************************/
unsigned char spi_recvbyte(void)
{
		int recv = 0, i = 0;
		for(i=7 ; i>=0 ;i--)
		{
				while(!CLK);                   //等待时钟线拉高，之后读取数据
				recv = recv << 1;              
				recv = recv | (IO ? 1 : 0);    //判断IO上的数据是否为1
				while(CLK);                    //等待时钟线拉低，进行下一位的数据读取
		}
		return recv;
}

/*********************************************
*函数名：Read_RxData
*功  能：读取SPI数据串
*参  数：数据接收指针   length 数据读取长度
*返回值：0：失败   1：读取成功
**********************************************/
void Read_Data( uint8_t *readData,  uint8_t length)
{
	uint8_t index = 0;
	while(CSN != 0);                    //等待片选拉低
	while(index < length)
	{
		readData[index] = spi_recvbyte();
		index++;
	}
}


/*********************************************
*函数名：Tx_Data
*功  能：SPI发送字符串数组
*参  数：void 
*返回值：void
**********************************************/
void Tx_Data(uint8_t *TxData ,uint8_t length)
{
	uint8_t index = 0;
	spi_cson();
	while(index < length)
	{
		spi_sendbyte(TxData[index]);
		index++;
	}	
	spi_csoff();
}

/*************************
*函数名字：OSD数据包检验
*函数功能：包的校验和计算
*参    数：void
*返 回 值：void
**************************/
uint8_t OSD_checksum(uint8_t OSD_DATA[])
{
		unsigned char i;
		unsigned char sum = OSD_DATA[0];
    for (i = 1; i < 3; i++)
    sum += OSD_DATA[i];
    return sum;
}