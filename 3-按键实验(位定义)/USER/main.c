#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"

int main(void)
{
 	vu8 key=0;	
	delay_init();	    	
 	LED_Init();			    
	KEY_Init();        
	LED0=0;				
	while(1)
	{
 		key = KEY_Scan(0);	
	   	if(key == 3)
		{						   
			LED0=!LED0;
		}else delay_ms(10); 
	}	 
}
