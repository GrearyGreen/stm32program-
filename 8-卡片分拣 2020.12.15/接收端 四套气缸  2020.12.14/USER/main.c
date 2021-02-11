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
u8 read_number;  //  nrfһ�ζ�ȡ32
u8 a1;
u8 b1;
u8 c1;
int main()
{			
	u8 tmp1_buf[33];
	delay_init();	    //��ʱ������ʼ��	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	uart_init(115200);
	TIM3_Int_Init(9999,7199);  //1s
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
  OLED_Init();
	BEEP_Init();
	KEY_Init();
	SMBus_Init();
 	TIM5_Cap_Init(0XFFFF,72-1);	//��1Mhz��Ƶ�ʼ���
	 NRF24L01_Init(); 
	 while(NRF24L01_Check())
	{
		OLED_P6x8Str(5,2,"NRF24L01 Error",1);
	}
	NRF24L01_RX_Mode();	
	OLED_P6x8Str(8,1,"ready",1);
		while(1)
		{
			if(NRF24L01_RxPacket(tmp1_buf)==0)//һ�����յ���Ϣ,����ʾ����.
			{
				r1[0]=tmp1_buf[0];
				Oled_Printf_U16(8,7,r1[0],0);
				
				switch(r1[0])
				{
//********��һ������**********
						case 112:   //����1ǰ��
						OLED_P6x8Str(8,0,"0",1);
						LED0=1;
						break;
						
			  	 case 113:      //����1����
				 	 OLED_P6x8Str(8,0,"1",1);
					 LED0=0;
					 break;
									
				    case 111:      //����1�½�
						OLED_P6x8Str(8,0,"2",1);					
						LED4=1;	
				    break;
				
				    case 110:      //����1����
						OLED_P6x8Str(8,0,"3",1);					
						LED4=0;
				    break;

//********�ڶ�������**********
				    case 131:   //����2ǰ��
						OLED_P6x8Str(8,8,"0",1);
						LED1=1;		
						break;
									
					 case 132:      //����2����
					 OLED_P6x8Str(8,8,"1",1);
					 LED1=0;	
					 break;
								
					 case 133:      //����2�½�
					 OLED_P6x8Str(8,0,"2",1);					
					 LED5=1;	
			     break;
								
					 case 134:      //����2����
					 OLED_P6x8Str(8,8,"3",1);					
					 LED5=0;		
				   break;
//********����������**********					
					 case 135:   //����3ǰ��
						OLED_P6x8Str(8,8,"0",1);
						LED2=1;		
						break;
									
					 case 136:      //����3����
					 OLED_P6x8Str(8,8,"1",1);
					 LED2=0;	
					 break;
								
					 case 137:      //����3�½�
					 OLED_P6x8Str(8,0,"2",1);					
					 LED6=1;	
			     break;
								
					 case 138:      //����3����
					 OLED_P6x8Str(8,8,"3",1);					
					 LED6=0;		
				   break;
//********����������**********					
					 case 140:   //����4ǰ��
						OLED_P6x8Str(8,8,"0",1);
						LED3=1;		
						break;
									
					 case 141:      //����4����
					 OLED_P6x8Str(8,8,"1",1);
					 LED3=0;	
					 break;
								
					 case 142:      //����4�½�
					 OLED_P6x8Str(8,0,"2",1);					
					 LED7=1;	
			     break;
								
					 case 143:      //����4����
					 OLED_P6x8Str(8,8,"3",1);					
					 LED7=0;		
				   break;
			
				}	
			
				
			}		
	   }
 }

