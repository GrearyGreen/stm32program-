#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "oled.h"
#include "delay.h"
#include "iic.h"
#include "lcd.h"
#include "key.h"
#include "timer.h"
#include "cbs.h"
#include "stmflash.h"
#include "beep.h"
#include "24l01.h"

u8 r1[32];
u8 read_number;  //  nrf一次读取32
u8 a1;
u8 b1;
u8 c1;
int main()
{			
	u8 tmp1_buf[33];
	delay_init();	    //延时函数初始化	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	uart_init(115200);
	TIM3_Int_Init(9999,7199);  //1s
	LED_Init();		  	//初始化与LED连接的硬件接口
  OLED_Init();
	BEEP_Init();
	KEY_Init();
	SMBus_Init();
 	TIM5_Cap_Init(0XFFFF,72-1);	//以1Mhz的频率计数
	 NRF24L01_Init(); 
	 while(NRF24L01_Check())
	{
		OLED_P6x8Str(5,2,"NRF24L01 Error",1);
	}
	NRF24L01_RX_Mode();	
	OLED_P6x8Str(8,1,"ready",1);
		while(1)
		{
			if(NRF24L01_RxPacket(tmp1_buf)==0)//一旦接收到信息,则显示出来.
			{
				r1[0]=tmp1_buf[0];
				Oled_Printf_U16(8,7,r1[0],0);
				
				switch(r1[0])
				{
//********第一套气缸**********
						case 112:   //气缸1前进
						OLED_P6x8Str(8,0,"0",1);
						LED0=1;
						break;
						
			  	 case 113:      //气缸1后退
				 	 OLED_P6x8Str(8,0,"1",1);
					 LED0=0;
					 break;
									
				    case 111:      //气缸1下降
						OLED_P6x8Str(8,0,"2",1);					
						LED4=1;	
				    break;
				
				    case 110:      //气缸1上升
						OLED_P6x8Str(8,0,"3",1);					
						LED4=0;
				    break;

//********第二套气缸**********
				    case 131:   //气缸2前进
						OLED_P6x8Str(8,8,"0",1);
						LED1=1;		
						break;
									
					 case 132:      //气缸2后退
					 OLED_P6x8Str(8,8,"1",1);
					 LED1=0;	
					 break;
								
					 case 133:      //气缸2下降
					 OLED_P6x8Str(8,0,"2",1);					
					 LED5=1;	
			     break;
								
					 case 134:      //气缸2上升
					 OLED_P6x8Str(8,8,"3",1);					
					 LED5=0;		
				   break;
//********第三套气缸**********					
					 case 135:   //气缸3前进
						OLED_P6x8Str(8,8,"0",1);
						LED2=1;		
						break;
									
					 case 136:      //气缸3后退
					 OLED_P6x8Str(8,8,"1",1);
					 LED2=0;	
					 break;
								
					 case 137:      //气缸3下降
					 OLED_P6x8Str(8,0,"2",1);					
					 LED6=1;	
			     break;
								
					 case 138:      //气缸3上升
					 OLED_P6x8Str(8,8,"3",1);					
					 LED6=0;		
				   break;
//********第四套气缸**********					
					 case 140:   //气缸4前进
						OLED_P6x8Str(8,8,"0",1);
						LED3=1;		
						break;
									
					 case 141:      //气缸4后退
					 OLED_P6x8Str(8,8,"1",1);
					 LED3=0;	
					 break;
								
					 case 142:      //气缸4下降
					 OLED_P6x8Str(8,0,"2",1);					
					 LED7=1;	
			     break;
								
					 case 143:      //气缸4上升
					 OLED_P6x8Str(8,8,"3",1);					
					 LED7=0;		
				   break;
			
				}	
			
				
			}		
	   }
 }

