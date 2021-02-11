#include "stm32f10x.h"
#include "oled.h"
#include "string.h"
#include "delay.h"
#include "usart.h"//串口调试
#include "usart3.h"//蓝牙需要的串口
#include "hc05.h"
//#include "stdio.h"
//#include "stdlib.h"
//1:选中状态，0：未选中状态
//蓝牙接收在USART3_RX_BUF里面可以通过，n = USART3_RX_BUF[x]来拿取
//蓝牙发送在u3_printf("%d\r\n",num);向手机端发送数据

int main(void)
{
	delay_init();//延迟初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);//串口调试的波特率
	OLED_Init();//oled初始化
	OLED_P8x16Str(2*16,2,"READAY",0);
	HC05_Init();//蓝牙初始化
	USART3_RX_STA=0;//蓝牙接收，标志初始化
	u3_printf("ready\r\n");
	printf("ready\r\n");
	while(1)
	{
		u8 reclen=0;
		if(USART3_RX_STA&0X8000)			//接收到一次数据了
		{
			reclen=USART3_RX_STA&0X7FFF;	//得到数据长度
			USART3_RX_BUF[reclen]=0;	 	//加入结束符
			
			printf("%s\r\n",USART3_RX_BUF);
			
			OLED_Fill(0x00);				//清屏
//			if(strcmp(USART3_RX_BUF,"0")==0)
//			{
//				OLED_P6x8Str(32,2,"200",0);//显示接收到的数据
//			}
			OLED_P8x16Str(2*16,2,USART3_RX_BUF,0);
			u3_printf("I get %s\r\n",USART3_RX_BUF);
//		if(strcmp(USART3_RX_BUF,"0")==0)//strcmp函数是string compare(字符串比较)的缩写，用于比较两个字符串并根据比较结果返回整数。
//				                               	//基本形式为strcmp(str1,str2)，若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数。
//		{
//			printf("jiayou\r\n");	//打开LED
//		}
//		if(strcmp(USART3_RX_BUF,"1")==0)
//		{	
//			MOTSET_left();
//			printf("jiayou\r\n");
//	    }
//		if(strcmp(USART3_RX_BUF,"2")==0)
//		{	
//			MOTSET_right();	
//	    }
//		if(strcmp(USART3_RX_BUF,"3")==0)
//		{	
//			MOTSET_back();
//	    }
//		if(strcmp(USART3_RX_BUF,"4")==0)
//		{	
//			MOTSET_stop();
//	    }
//		if(strcmp(USART3_RX_BUF,"5")==0)
//		{	
//			PWM1=PWM1+10;
//	    }
//		if(strcmp(USART3_RX_BUF,"6")==0)
//		{	
//			PWM1=PWM1-10;
//	    }
////        if(strcmp(USART3_RX_BUF,"4")==0)
////				{	
////				t2=t2+10;	
////	      }
////				if(strcmp(USART3_RX_BUF,"5")==0)
////				{	
////				t2=t2-10;	
////	      }
////				if(strcmp(USART3_RX_BUF,"6")==0)
////				{	
////				MOTSET_stop();
////	      }
//			OLED_CLS();
//			OLED_P6x8Str(32,2,USART3_RX_BUF,0);//显示接收到的数据
//		printf("%s",USART3_RX_BUF);
//		u3_printf("%s\r\n",USART3_RX_BUF);//返回给发送端发送数据
//			
			USART3_RX_STA=0;//接受标志初始化
		}
	}		
}
