#include "key.h"
#include "stm32f10x.h"
#include "delay.h"
#include "sys.h" 
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(KEY2 == 0))
	{
		delay_ms(10);//去抖动 
		key_up=0;
		if(KEY2==0)
		{
			return 1;
		}
	}else if(KEY2==1)
	{
		key_up=1;
	}		
 	return 0;// 无按键按下
}
