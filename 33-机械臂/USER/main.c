#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"

 
/************************************************
 ALIENTEKս��STM32������ʵ��9
 PWM���ʵ��  
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
void reset(void);
void left(void);
void right(void);		
	
int main(void)
{		
	u16 key=0;
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
	KEY_Init();
 	TIM3_PWM_Init(1999,719);	 //20ms���� �����������
 
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
 
	//	TIM_SetCompare3(TIM3,185);  //��е��185�ſ� PB0 182��£
	// 	TIM_SetCompare2(TIM3,193); //       PB5 ��193 ��185  5�Ż�
  //  TIM_SetCompare4(TIM3,187);  //PB1    194��   178��   4�Ż�

	 
	 
	 
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
	  TIM_SetCompare2(TIM3,188); //       PB5 ��193 ��185  5�Ż�
	  delay_ms(500);
	  TIM_SetCompare4(TIM3,187);  //PB1    194��   178��   4�Ż�
	  delay_ms(500); 
		TIM_SetCompare2(TIM3,194); //       PB5 ��193 ��185  5�Ż�
	  delay_ms(500);
	  printf("%s","OK");
}
void left(void)
{    printf("%s","left");
	  TIM_SetCompare3(TIM3,182);  //��е��185�ſ� PB0 182��£
	  delay_ms(500);
    TIM_SetCompare2(TIM3,188); //       PB5 ��193 ��185  5�Ż�
	  delay_ms(500);
  	TIM_SetCompare4(TIM3,191);  //PB1    194��   178��   4�Ż�
	  delay_ms(500); 
    TIM_SetCompare2(TIM3,193); //       PB5 ��193 ��185  5�Ż�
	  delay_ms(500);
	  TIM_SetCompare3(TIM3,185);  //��е��185�ſ� PB0 182��£
	  delay_ms(500);
	 printf("%s","OK");
	 reset();
}

void right(void)
{   printf("%s","right");
    TIM_SetCompare3(TIM3,182);  //��е��185�ſ� PB0 182��£
	  delay_ms(500);
    TIM_SetCompare2(TIM3,188); //       PB5 ��193 ��185  5�Ż�
	  delay_ms(500);
  	TIM_SetCompare4(TIM3,182);  //PB1    194��   178��   4�Ż�
	  delay_ms(500); 
    TIM_SetCompare2(TIM3,193); //       PB5 ��193 ��185  5�Ż�
	  delay_ms(500);
	  TIM_SetCompare3(TIM3,185);  //��е��185�ſ� PB0 182��£
	  delay_ms(500);
    printf("%s","OK");
	 reset();
}
*/
}
