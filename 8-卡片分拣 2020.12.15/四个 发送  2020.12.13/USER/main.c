#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "string.h"
#include "ov7670.h"
#include "tpad.h"
#include "timer.h"
#include "exti.h"
#include "usmart.h"
#include  "oled.h"
#include "RD.h"
#include "math.h"
#include "driver.h"
#include "bjdj.h"
#include "24l01.h"
// #include "OLED_I2C.h"
/************************************************
 ALIENTEK战舰STM32开发板实验35
 摄像头OV7670 实验
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

u8 r2=0;
u8 exti_key=0;
u8 i;
u16 z=0;
//u16 v=1;
u32 x ,y;
int main(void)
 {	 
//	 u8 key;	 
	u8 tmp1_buf[33];  
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为 115200
  	KEY_Init();					//初始化按键
	NRF24L01_Init();  
	OLED_Init();
	LED_Init();
	EXTIX_Init();
	while(NRF24L01_Check())
	{
		OLED_P6x8Str(5,2,"NRF24L01 Error",1);
		delay_ms(200);
	}
	NRF24L01_TX_Mode();
		OLED_P6x8Str(5,1,"ready",1);
	while(1)
	{	

    while(exti_key==1)//运行模式
			{
				LED1=!LED1;
				OLED_P6x8Str(5,0,"1",1);		
//********第一个光电开关检测*********				
			if(z==0)
			{
				if(led_switch==1)    //光电检测开关1      为1时传输带运行
					{
						belt=1;
						OLED_P6x8Str(5,6,"run",1);
         z=1;			//跳到光电开关2检测		
					}
				else if(led_switch==0)  //       0时传输带停止
					{  
						belt=0;
						OLED_P6x8Str(5,6,"stop",1);	
						tmp1_buf[0]=111;//气缸下
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						NRF24L01_TxPacket(tmp1_buf);
						delay_ms(500);
				
						tmp1_buf[0]=115;//吸盘吸
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);
         

				    tmp1_buf[0]=110;//气缸上
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						 delay_ms(500);
					
					tmp1_buf[0]=112;//气缸前
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);



						tmp1_buf[0]=111;//气缸下
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);


						tmp1_buf[0]=120;//吸盘关			  
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

			
					  tmp1_buf[0]=110;//气缸上
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

 	
						tmp1_buf[0]=113;//气缸回
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
            LED1=!LED1;
				
     				belt=1;		
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(500);
						
					}	
				}		
//********第二个光电开关检测*********			
if(z==1)	//如果光电开关1未检测到障碍物，则跳到这段代码，光电开关2检测
{	
						if(led_switch2==1)    //光电检测开关      为1时传输带运行
					{
						belt=1;
						OLED_P6x8Str(5,6,"run",1);	
						z=2;    //如果光电开关2没检测到，跳到光电开关3
					}
					else if(led_switch2==0)  //光电开关检测有障碍物  停止运行
					{
							belt=0;
	          OLED_P6x8Str(5,6,"stop",1);	
				
            tmp1_buf[0]=133;//气缸2 下
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						NRF24L01_TxPacket(tmp1_buf);
						delay_ms(500);
				
						tmp1_buf[0]=125;//吸盘2组 吸
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);
         

				    tmp1_buf[0]=134;//气缸2上
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						 delay_ms(500);
					
					tmp1_buf[0]=131;//2气缸前
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);



						tmp1_buf[0]=133;//气缸2下
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);


						tmp1_buf[0]=130;//吸盘2关			  
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

			
					  tmp1_buf[0]=134;//2气缸上
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

 	
						tmp1_buf[0]=132;//2气缸回
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
            LED1=!LED1;
				
     				belt=1;		
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);		
						delay_ms(1000);
						delay_ms(500);
					}
				}
//********第三个光电开关检测*********			
if(z==2)	//如果光电开关2未检测到障碍物，则跳到这段代码，光电开关3检测
{	
						if(led_switch3==1)    //光电检测开关3      为1时传输带运行
					{
						belt=1;
						OLED_P6x8Str(5,6,"run",1);	
						z=3;    //如果光电开关3没检测到，跳到光电开关4
					}
					else if(led_switch3==0)  //光电开关检测有障碍物  停止运行
					{
						belt=0;
	          OLED_P6x8Str(5,6,"stop",1);	
				
            tmp1_buf[0]=137;//气缸3 下
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						NRF24L01_TxPacket(tmp1_buf);
						delay_ms(500);
				
						tmp1_buf[0]=121;//吸盘3组 吸
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);
         

				    tmp1_buf[0]=138;//气缸3上
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						 delay_ms(500);
					
					tmp1_buf[0]=135;//3气缸前
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);



						tmp1_buf[0]=137;//气缸3下
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);


						tmp1_buf[0]=122;//吸盘3关			  
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

			
					  tmp1_buf[0]=138;//3气缸上
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

 	
						tmp1_buf[0]=136;//3气缸回
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
            LED1=!LED1;
				
     				belt=1;		
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);		
						delay_ms(1000);
						delay_ms(500);
					}

}		
//********第四个光电开关检测*********			
if(z==3)	//如果光电开关3未检测到障碍物，则跳到这段代码，光电开关4检测
{	
						if(led_switch4==1)    //光电检测开关3      为1时传输带运行
					{
						belt=1;
						OLED_P6x8Str(5,6,"run",1);	
						z=0;    //如果光电开关4没检测到，跳回光电开关1检测
					}
					else if(led_switch4==0)  //光电开关检测有障碍物  停止运行
					{
						belt=0;
	          OLED_P6x8Str(5,6,"stop",1);	
				
            tmp1_buf[0]=142;//气缸4 下
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						NRF24L01_TxPacket(tmp1_buf);
						delay_ms(500);
				
						tmp1_buf[0]=123;//吸盘4组 吸
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);
         

				    tmp1_buf[0]=143;//气缸4上
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						 delay_ms(500);
					
					  tmp1_buf[0]=140;//4气缸前
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);



						tmp1_buf[0]=142;//气缸4下
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);


						tmp1_buf[0]=124;//吸盘4关			  
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

			
					  tmp1_buf[0]=143;//4气缸上
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

 	
						tmp1_buf[0]=141;//4气缸回
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
            LED1=!LED1;
				
     				belt=1;		
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);		
						delay_ms(1000);
						delay_ms(500);
					}

}	

Oled_Printf_U16(64,0,z,0);
			}
			
     while(exti_key==2)//退回模式
			 {
				 LED1=!LED1;
			    belt=0;//传送带关闭  	  	
				  OLED_P6x8Str(5,0,"2",1);	 
				  tmp1_buf[0]=120;//吸盘1关
				  NRF24L01_TxPacket(tmp1_buf);
				  delay_ms(500);
				  tmp1_buf[0]=110;//1气缸上
				  NRF24L01_TxPacket(tmp1_buf);
				  delay_ms(500);
				  tmp1_buf[0]=113;//气缸1回
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				  tmp1_buf[0]=130;//吸盘2关			  
			  	NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				 	tmp1_buf[0]=134;//2气缸上
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				  tmp1_buf[0]=132;//2气缸回
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				  OLED_P6x8Str(5,4,"back finish",1);
		
      		tmp1_buf[0]=122;//吸盘3关			  
			  	NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				 	tmp1_buf[0]=137;//3气缸上
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				  tmp1_buf[0]=136;//3气缸回
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
					 
					  tmp1_buf[0]=124;//吸盘4关			  
			  	NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				 	tmp1_buf[0]=142;//4气缸上
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				  tmp1_buf[0]=141;//4气缸回
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
					 
				  exti_key=0;                           //置位为0
				 
			 }
  }

}




