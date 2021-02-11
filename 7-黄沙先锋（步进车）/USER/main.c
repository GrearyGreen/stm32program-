//#include <stdio.h>
#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "move.h"
#include "oled.h"
#include "timer.h"
#include "math.h"
#include "usart3.h"
#include "spi.h"
#include "24l01.h"
/************************************************
 ALIENTEK 战舰STM32F103开发板实验17
 ADC 实验 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

u8 reclen=0;
void HC06_receive(void) ; 
 int main(void)
 {	 
//  float t=1.0;
//	float dis1;
//  u16 adc1,adc2;
//	float temp1,temp2;
	u8 tmp_buf[5];
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
	usart3_init(9600);	//初始化串口2为:9600,波特率.//这里是115200是因为模块AT更改了
	MOVE_Init();
	TIM3_Int_Init(1200,79);  //1000us
	OLED_Init();
 	LED_Init();			     //LED端口初始化
	KEY_Init();
//	LCD_Init();			 	
// 	Adc_Init();		  		//ADC初始化
	NRF24L01_Init();
	stop();
	 
//	while(NRF24L01_Check())
//	{
// 		delay_ms(400);
//	}
	NRF24L01_RX_Mode();
	stop();
	
	while(1)
	{
		HC06_receive();/// 蓝牙控制		
		//delay_ms(250);	
		OLED_P8x16Str(2,6,"READY",0);
		if(NRF24L01_RxPacket(tmp_buf)==0)
			{  
				switch (tmp_buf[0])
				{
					case UP_PRES: goForward();break;
					case DOWN_PRES:goBack();break;
					case LEFT_PRES:turnLeft();break;
					case RIGHT_PRES:turnRight();break;
//					case KEY0_PRES: stop();break;
//					case KEY1_PRES: goForward();break;
					case SPEED_UP_PRES :speedUp();break;
					case SPEED_DOWN_PRES:speedDown();break;
					case STOP_PRES:stop();break;
				}
				
			}
	}
 }
 void HC06_receive(void)                 //接收函数 
{  u8 reclen=0;
	if(USART3_RX_STA&0X8000)			//接收到一次数据了
		{
			
 			reclen=USART3_RX_STA&0X7FFF;	//得到数据长度
		  	USART3_RX_BUF[reclen]=0;	 	//加入结束符

				if(strcmp(USART3_RX_BUF,"0")==0)//strcmp函数是string compare(字符串比较)的缩写，用于比较两个字符串并根据比较结果返回整数。
				                               	//基本形式为strcmp(str1,str2)，若str1=str2，则返回零；若str1<str2，则返回负数；若str1>str2，则返回正数。
				{
				LED0=!LED0;	//打开LED
				}
				
// 			 OLED_P6x8Str(2,4,USART3_RX_BUF,0);//显示接收到的数据
				printf("%s",USART3_RX_BUF);
			u3_printf("%s\r\n",USART3_RX_BUF);//返回给发送端发送数据
			
 			USART3_RX_STA=0;	 
		}	 															     
}
