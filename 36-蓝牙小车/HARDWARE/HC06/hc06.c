#include "delay.h" 			 
#include "usart.h" 			 
#include "usart3.h" 			 
#include "hc06.h" 
#include "led.h" 
#include "string.h"	 
#include "math.h"
#include  "oled.h"
#include "L29.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32开发板
//ATK-HC05蓝牙模块驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2015/3/29
//版本：V1.1
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//********************************************************************************
//V1.1 20140329
//修改LED的连接，原来接PC5，改为PA4，以兼容MiniSTM32开发板V3.0									  
////////////////////////////////////////////////////////////////////////////////// 	   

//初始化ATK-HC06模块
//返回值:0,成功;1,失败.
extern	u16 PWM1;
extern int t1,t2;
void HC06_Init(void)
{
	usart3_init(9600);	//初始化串口2为:9600,波特率.//这里是115200是因为模块AT更改了
}	 
void HC06_receive(void)                 //接收函数 
{  	
	u8 reclen=0;
	if(USART3_RX_STA&0X8000)			//接收到一次数据了
	{
			
 		reclen=USART3_RX_STA&0X7FFF;	//得到数据长度
		USART3_RX_BUF[reclen]=0;	 	//加入结束符

		if(strcmp(USART3_RX_BUF,"0")==0)//strcmp函数是string compare(字符串比较)的缩写，用于比较两个字符串并根据比较结果返回整数。
				                               	//基本形式为strcmp(str1,str2)，若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数。
		{
			MOTSET_front();	//打开LED
		}
		if(strcmp(USART3_RX_BUF,"1")==0)
		{	
			MOTSET_left();	
	    }
		if(strcmp(USART3_RX_BUF,"2")==0)
		{	
			MOTSET_right();	
	    }
		if(strcmp(USART3_RX_BUF,"3")==0)
		{	
			MOTSET_back();
	    }
		if(strcmp(USART3_RX_BUF,"4")==0)
		{	
			MOTSET_stop();
	    }
		if(strcmp(USART3_RX_BUF,"5")==0)
		{	
			PWM1=PWM1+10;
	    }
		if(strcmp(USART3_RX_BUF,"6")==0)
		{	
			PWM1=PWM1-10;
	    }
//        if(strcmp(USART3_RX_BUF,"4")==0)
//				{	
//				t2=t2+10;	
//	      }
//				if(strcmp(USART3_RX_BUF,"5")==0)
//				{	
//				t2=t2-10;	
//	      }
//				if(strcmp(USART3_RX_BUF,"6")==0)
//				{	
//				MOTSET_stop();
//	      }
 		OLED_P6x8Str(2,4,USART3_RX_BUF,0);//显示接收到的数据
		printf("%s",USART3_RX_BUF);
		u3_printf("%s\r\n",USART3_RX_BUF);//返回给发送端发送数据
			
 		USART3_RX_STA=0;	 
	}	 															     
}








