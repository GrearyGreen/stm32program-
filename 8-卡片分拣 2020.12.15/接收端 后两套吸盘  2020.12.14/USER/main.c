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
			
					case 121:   //四个吸盘同时工作		，置高			
				OLED_P6x8Str(8,5,"catch",1);	
              sucker0=1;
					    sucker1=1;	
				    	sucker2=1;	
				    	sucker3=1;		
          break;					
					case 122:   //置低			
				OLED_P6x8Str(8,5,"set",1);	
             sucker0=0;
					    sucker1=0;	
				    	sucker2=0;	
				    	sucker3=0;	
          break;	
        					
					case 123:   //四个吸盘同时工作		，置高			
				  OLED_P6x8Str(8,5,"catch1",1);	
					    sucker4=1;
					    sucker5=1;	
				    	sucker6=1;			
			    	sucker7=1;		
        	break;		
					case 124:   //置低			
				  OLED_P6x8Str(8,5,"set1",1);		
					    sucker4=0;
					    sucker5=0;	
				    	sucker6=0;			
			    	  sucker7=0;
          break;	
					
				}					
			}		
	   }
 }


