#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "string.h"
#include "ov7670.h"
#include "tpad.h"
#include "timer.h"
#include "exti.h"
#include "usmart.h"
#include  "oled.h"
#include "RD.h"
#include "math.h"
#include "driver.h"
#include "bjdj.h"
#include "24l01.h"
// #include "OLED_I2C.h"
/************************************************
 ALIENTEKս��STM32������ʵ��35
 ����ͷOV7670 ʵ��
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

u8 r2=0;
u8 exti_key=0;
u8 i;
u16 z=0;
//u16 v=1;
u32 x ,y;
int main(void)
 {	 
//	 u8 key;	 
	u8 tmp1_buf[33];  
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ 115200
  	KEY_Init();					//��ʼ������
	NRF24L01_Init();  
	OLED_Init();
	LED_Init();
	EXTIX_Init();
	while(NRF24L01_Check())
	{
		OLED_P6x8Str(5,2,"NRF24L01 Error",1);
		delay_ms(200);
	}
	NRF24L01_TX_Mode();
		OLED_P6x8Str(5,1,"ready",1);
	while(1)
	{	

    while(exti_key==1)//����ģʽ
			{
				LED1=!LED1;
				OLED_P6x8Str(5,0,"1",1);		
//********��һ����翪�ؼ��*********				
			if(z==0)
			{
				if(led_switch==1)    //����⿪��1      Ϊ1ʱ���������
					{
						belt=1;
						OLED_P6x8Str(5,6,"run",1);
         z=1;			//������翪��2���		
					}
				else if(led_switch==0)  //       0ʱ�����ֹͣ
					{  
						belt=0;
						OLED_P6x8Str(5,6,"stop",1);	
						tmp1_buf[0]=111;//������
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						NRF24L01_TxPacket(tmp1_buf);
						delay_ms(500);
				
						tmp1_buf[0]=115;//������
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);
         

				    tmp1_buf[0]=110;//������
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						 delay_ms(500);
					
					tmp1_buf[0]=112;//����ǰ
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);



						tmp1_buf[0]=111;//������
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);


						tmp1_buf[0]=120;//���̹�			  
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

			
					  tmp1_buf[0]=110;//������
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

 	
						tmp1_buf[0]=113;//���׻�
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
            LED1=!LED1;
				
     				belt=1;		
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(500);
						
					}	
				}		
//********�ڶ�����翪�ؼ��*********			
if(z==1)	//�����翪��1δ��⵽�ϰ����������δ��룬��翪��2���
{	
						if(led_switch2==1)    //����⿪��      Ϊ1ʱ���������
					{
						belt=1;
						OLED_P6x8Str(5,6,"run",1);	
						z=2;    //�����翪��2û��⵽��������翪��3
					}
					else if(led_switch2==0)  //��翪�ؼ�����ϰ���  ֹͣ����
					{
							belt=0;
	          OLED_P6x8Str(5,6,"stop",1);	
				
            tmp1_buf[0]=133;//����2 ��
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						NRF24L01_TxPacket(tmp1_buf);
						delay_ms(500);
				
						tmp1_buf[0]=125;//����2�� ��
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);
         

				    tmp1_buf[0]=134;//����2��
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						 delay_ms(500);
					
					tmp1_buf[0]=131;//2����ǰ
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);



						tmp1_buf[0]=133;//����2��
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);


						tmp1_buf[0]=130;//����2��			  
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

			
					  tmp1_buf[0]=134;//2������
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

 	
						tmp1_buf[0]=132;//2���׻�
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
            LED1=!LED1;
				
     				belt=1;		
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);		
						delay_ms(1000);
						delay_ms(500);
					}
				}
//********��������翪�ؼ��*********			
if(z==2)	//�����翪��2δ��⵽�ϰ����������δ��룬��翪��3���
{	
						if(led_switch3==1)    //����⿪��3      Ϊ1ʱ���������
					{
						belt=1;
						OLED_P6x8Str(5,6,"run",1);	
						z=3;    //�����翪��3û��⵽��������翪��4
					}
					else if(led_switch3==0)  //��翪�ؼ�����ϰ���  ֹͣ����
					{
						belt=0;
	          OLED_P6x8Str(5,6,"stop",1);	
				
            tmp1_buf[0]=137;//����3 ��
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						NRF24L01_TxPacket(tmp1_buf);
						delay_ms(500);
				
						tmp1_buf[0]=121;//����3�� ��
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);
         

				    tmp1_buf[0]=138;//����3��
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						 delay_ms(500);
					
					tmp1_buf[0]=135;//3����ǰ
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);



						tmp1_buf[0]=137;//����3��
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);


						tmp1_buf[0]=122;//����3��			  
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

			
					  tmp1_buf[0]=138;//3������
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

 	
						tmp1_buf[0]=136;//3���׻�
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
            LED1=!LED1;
				
     				belt=1;		
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);		
						delay_ms(1000);
						delay_ms(500);
					}

}		
//********���ĸ���翪�ؼ��*********			
if(z==3)	//�����翪��3δ��⵽�ϰ����������δ��룬��翪��4���
{	
						if(led_switch4==1)    //����⿪��3      Ϊ1ʱ���������
					{
						belt=1;
						OLED_P6x8Str(5,6,"run",1);	
						z=0;    //�����翪��4û��⵽�����ع�翪��1���
					}
					else if(led_switch4==0)  //��翪�ؼ�����ϰ���  ֹͣ����
					{
						belt=0;
	          OLED_P6x8Str(5,6,"stop",1);	
				
            tmp1_buf[0]=142;//����4 ��
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						NRF24L01_TxPacket(tmp1_buf);
						delay_ms(500);
				
						tmp1_buf[0]=123;//����4�� ��
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);
         

				    tmp1_buf[0]=143;//����4��
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						 delay_ms(500);
					
					  tmp1_buf[0]=140;//4����ǰ
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);



						tmp1_buf[0]=142;//����4��
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);


						tmp1_buf[0]=124;//����4��			  
						NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

			
					  tmp1_buf[0]=143;//4������
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
						delay_ms(500);

 	
						tmp1_buf[0]=141;//4���׻�
				    NRF24L01_TxPacket(tmp1_buf);
						Oled_Printf_U16(5,3,tmp1_buf[0],0);
            LED1=!LED1;
				
     				belt=1;		
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);
						delay_ms(1000);		
						delay_ms(1000);
						delay_ms(500);
					}

}	

Oled_Printf_U16(64,0,z,0);
			}
			
     while(exti_key==2)//�˻�ģʽ
			 {
				 LED1=!LED1;
			    belt=0;//���ʹ��ر�  	  	
				  OLED_P6x8Str(5,0,"2",1);	 
				  tmp1_buf[0]=120;//����1��
				  NRF24L01_TxPacket(tmp1_buf);
				  delay_ms(500);
				  tmp1_buf[0]=110;//1������
				  NRF24L01_TxPacket(tmp1_buf);
				  delay_ms(500);
				  tmp1_buf[0]=113;//����1��
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				  tmp1_buf[0]=130;//����2��			  
			  	NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				 	tmp1_buf[0]=134;//2������
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				  tmp1_buf[0]=132;//2���׻�
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				  OLED_P6x8Str(5,4,"back finish",1);
		
      		tmp1_buf[0]=122;//����3��			  
			  	NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				 	tmp1_buf[0]=137;//3������
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				  tmp1_buf[0]=136;//3���׻�
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
					 
					  tmp1_buf[0]=124;//����4��			  
			  	NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				 	tmp1_buf[0]=142;//4������
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
				  tmp1_buf[0]=141;//4���׻�
				  NRF24L01_TxPacket(tmp1_buf);
				   delay_ms(500);
					 
				  exti_key=0;                           //��λΪ0
				 
			 }
  }

}




