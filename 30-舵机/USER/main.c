#include "stm32f10x.h"
#include "delay.h"
#include "timer.h"

 int main(void)
 {		
// 	u16 pAwmval=0;
//	u16 pBwmval=0;
	u16 pCwmval=0;
	u16 pDwmval=0;
	u8 dir = 0;
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,DISABLE);
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,DISABLE);
	delay_init();	    	 //延时函数初始化
// 	TIM3_PWM_Init(899,0);	 //不分频。PWM频率=72000000/900=80Khz
	TIM3_PWM_Init(1999,719);
   	while(1)
	{
//		pAwmval = 1000;
//		pBwmval = 3000;
//		TIM_SetCompare1(TIM3,pAwmval);
//		TIM_SetCompare2(TIM3,pBwmval);
		for(dir = 0;dir < 240;dir +=5)
		{
			pCwmval = dir;
			TIM_SetCompare3(TIM3,pCwmval);
			delay_ms(50);
		}
		for(dir = 240;0<dir;dir -=5)
		{
			pCwmval = dir;
			TIM_SetCompare3(TIM3,pCwmval);
			delay_ms(50);
		}
		TIM_SetCompare4(TIM3,pDwmval);		
	}	 
 }
