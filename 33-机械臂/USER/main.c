#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"

 
/************************************************
 ALIENTEK战舰STM32开发板实验9
 PWM输出实验  
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
void reset(void);
void left(void);
void right(void);		
	
int main(void)
{		
	u16 key=0;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
	KEY_Init();
 	TIM3_PWM_Init(1999,719);	 //20ms周期 舵机动作周期
 
	while(1)
	{
		for(key=1825;key<=1920;key++)
		{
			TIM_SetCompare2(TIM3,key);
			delay_ms(10);
			if(key==1920)
			for(key=1920;key>=1825;key--)
			{
				TIM_SetCompare2(TIM3,key); 
				delay_ms(10);
			}
		}
	}
 
	//	TIM_SetCompare3(TIM3,185);  //机械手185张开 PB0 182合拢
	// 	TIM_SetCompare2(TIM3,193); //       PB5 下193 上185  5号机
  //  TIM_SetCompare4(TIM3,187);  //PB1    194左   178右   4号机

	 
	 
	 
// reset();

	/* while(1)
	 { key=KEY_Scan(0);
		 if(key==1)  //KEY1  PE3
    		{  delay_ms(300);			
				   reset();
				} 
		 if(key==2) // KEY2  PE2
		 { delay_ms(300);
       left();	
      			 
		 }
     if(key==3)  //KEY0 PE4
     { delay_ms(300);
			 right();	 
		 
		 }			 
	 } 
 }
void reset(void)
{   printf("%s","RESET");
	  TIM_SetCompare2(TIM3,188); //       PB5 下193 上185  5号机
	  delay_ms(500);
	  TIM_SetCompare4(TIM3,187);  //PB1    194左   178右   4号机
	  delay_ms(500); 
		TIM_SetCompare2(TIM3,194); //       PB5 下193 上185  5号机
	  delay_ms(500);
	  printf("%s","OK");
}
void left(void)
{    printf("%s","left");
	  TIM_SetCompare3(TIM3,182);  //机械手185张开 PB0 182合拢
	  delay_ms(500);
    TIM_SetCompare2(TIM3,188); //       PB5 下193 上185  5号机
	  delay_ms(500);
  	TIM_SetCompare4(TIM3,191);  //PB1    194左   178右   4号机
	  delay_ms(500); 
    TIM_SetCompare2(TIM3,193); //       PB5 下193 上185  5号机
	  delay_ms(500);
	  TIM_SetCompare3(TIM3,185);  //机械手185张开 PB0 182合拢
	  delay_ms(500);
	 printf("%s","OK");
	 reset();
}

void right(void)
{   printf("%s","right");
    TIM_SetCompare3(TIM3,182);  //机械手185张开 PB0 182合拢
	  delay_ms(500);
    TIM_SetCompare2(TIM3,188); //       PB5 下193 上185  5号机
	  delay_ms(500);
  	TIM_SetCompare4(TIM3,182);  //PB1    194左   178右   4号机
	  delay_ms(500); 
    TIM_SetCompare2(TIM3,193); //       PB5 下193 上185  5号机
	  delay_ms(500);
	  TIM_SetCompare3(TIM3,185);  //机械手185张开 PB0 182合拢
	  delay_ms(500);
    printf("%s","OK");
	 reset();
}
*/
}
