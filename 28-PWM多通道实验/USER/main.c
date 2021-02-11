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
	u16 pEwmval=0;
	u16 pFwmval=0;
	u16 pGwmval=0;
	u16 pHwmval=0;
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,DISABLE);
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,DISABLE);
	delay_init();	    	 //延时函数初始化
// 	TIM3_PWM_Init(899,0);	 //不分频。PWM频率=72000000/900=80Khz
	TIM3_PWM_Init(7199,0);
	TIM4_PWM_Init(7199,0);
   	while(1)
	{
		u8 i;
		pAwmval = 1000;
		pBwmval = 3000;
		pCwmval = 5000;
		pDwmval = 7000;
		pEwmval = 1000;
		pFwmval = 3000;
		pGwmval = 5000;
		pHwmval = 7000;
		for(i = 0;i<100;i++)
		if(i<50)
		{
			TIM_SetCompare1(TIM3,pAwmval);
			TIM_SetCompare2(TIM3,pBwmval);
			TIM_SetCompare3(TIM3,pCwmval);
			TIM_SetCompare4(TIM3,pDwmval);
			delay_us(10);
		}else{
			TIM_SetCompare1(TIM4,pEwmval);
			TIM_SetCompare2(TIM4,pFwmval);
			TIM_SetCompare3(TIM4,pGwmval);
			TIM_SetCompare4(TIM4,pHwmval);
			delay_us(10);
		}			
	}	 
 }
