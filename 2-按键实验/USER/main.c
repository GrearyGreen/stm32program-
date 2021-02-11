#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "led.h"

int main(void)
{	
	u8 key;
	LED_Iint();
	delay_init();
     LED1=0;	
	delay_ms(500);
     LED1=1;	
	delay_ms(500);
	LED1=0;

	KEY_Init();

	while(1)
	{
		key=KEY_Scan(0);
		if(key==1)
		{
		GPIO_ResetBits(GPIOE,GPIO_Pin_5);
		}
//	    if(KEY2 == 0)
//		{
//			delay_ms(10);//È¥¶¶¶¯ 
//			if(KEY2==0)
//			{
//				GPIO_ResetBits(GPIOE,GPIO_Pin_5);
//			}
//		}
	}
}
