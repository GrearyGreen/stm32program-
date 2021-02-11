#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "timer.h"
	
 int main(void)
 {		
 	u16 pAwmval=0;
	u16 pBwmval=0;
	u16 pCwmval=0;
	u16 pDwmval=0;
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,DISABLE);
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,DISABLE);
	delay_init();	    	 //延时函数初始化
// 	TIM3_PWM_Init(899,0);	 //不分频。PWM频率=72000000/900=80Khz
	TIM3_PWM_Init(7199,0);
   	while(1)
	{
		pAwmval = 1000;
		pBwmval = 3000;
		pCwmval = 5000;
		pDwmval = 7000;
		TIM_SetCompare1(TIM3,pAwmval);
		TIM_SetCompare2(TIM3,pBwmval);
		TIM_SetCompare3(TIM3,pCwmval);
		TIM_SetCompare4(TIM3,pDwmval);		
	}	 
 }
