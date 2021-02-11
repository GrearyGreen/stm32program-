#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
#include "L29.h" 
#include "usart3.h" 			 
#include "hc06.h" 
#include  "oled.h"
#include "24l01.h"
/************************************************
 ALIENTEKս��STM32������ʵ��9
 PWM���ʵ��  
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
u16 PWM1=699;
	
int main(void)
{	
	u8 key;	
	u16 MT1=15,MT2=15;	
	u8 tmp_buf[33];	
	u8 r1,y1;	   	 
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(9600);
	usart3_init(9600);
 	LED_Init();			     //LED�˿ڳ�ʼ��
 	TIM3_PWM_Init(199,7199);	 //����Ƶ��PWMƵ��=72000000/900=80Khz
	TIM4_PWM_Init(899,0);
	GPIOUT_Init();
	MOTSET_stop();
	OLED_Init();
	KEY_Init();
	 
	NRF24L01_Init(); 
	while(NRF24L01_Check())  //nrfģ�����м����
	{
		OLED_P6x8Str(5,2,"NRF24L01 Error",1);
	}
	NRF24L01_RX_Mode();	//�������ģʽ
   	while(1)
	{
		 
		HC06_receive();
		if(NRF24L01_RxPacket(tmp_buf)==0)//һ�����յ���Ϣ,����ʾ����.
		{
			r1=tmp_buf[0];
			Oled_Printf_U16(8,3,r1,0);
		}
		if(r1==112)MOTSET_front();
		else if(r1==111)MOTSET_back();
		else if(r1==113)MOTSET_left();
		else if(r1==114)MOTSET_right();
		else if(r1==180)MOTSET_stop();	
			
		TIM_SetCompare1(TIM4,PWM1);
		TIM_SetCompare2(TIM4,PWM1);
		TIM_SetCompare3(TIM4,PWM1);
		TIM_SetCompare4(TIM4,PWM1);
		Oled_Printf_U16(0,0,PWM1,0);

	}	 
 }

