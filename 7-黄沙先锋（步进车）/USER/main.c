//#include <stdio.h>
#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "move.h"
#include "oled.h"
#include "timer.h"
#include "math.h"
#include "usart3.h"
#include "spi.h"
#include "24l01.h"
/************************************************
 ALIENTEK ս��STM32F103������ʵ��17
 ADC ʵ�� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

u8 reclen=0;
void HC06_receive(void) ; 
 int main(void)
 {	 
//  float t=1.0;
//	float dis1;
//  u16 adc1,adc2;
//	float temp1,temp2;
	u8 tmp_buf[5];
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
	usart3_init(9600);	//��ʼ������2Ϊ:9600,������.//������115200����Ϊģ��AT������
	MOVE_Init();
	TIM3_Int_Init(1200,79);  //1000us
	OLED_Init();
 	LED_Init();			     //LED�˿ڳ�ʼ��
	KEY_Init();
//	LCD_Init();			 	
// 	Adc_Init();		  		//ADC��ʼ��
	NRF24L01_Init();
	stop();
	 
//	while(NRF24L01_Check())
//	{
// 		delay_ms(400);
//	}
	NRF24L01_RX_Mode();
	stop();
	
	while(1)
	{
		HC06_receive();/// ��������		
		//delay_ms(250);	
		OLED_P8x16Str(2,6,"READY",0);
		if(NRF24L01_RxPacket(tmp_buf)==0)
			{  
				switch (tmp_buf[0])
				{
					case UP_PRES: goForward();break;
					case DOWN_PRES:goBack();break;
					case LEFT_PRES:turnLeft();break;
					case RIGHT_PRES:turnRight();break;
//					case KEY0_PRES: stop();break;
//					case KEY1_PRES: goForward();break;
					case SPEED_UP_PRES :speedUp();break;
					case SPEED_DOWN_PRES:speedDown();break;
					case STOP_PRES:stop();break;
				}
				
			}
	}
 }
 void HC06_receive(void)                 //���պ��� 
{  u8 reclen=0;
	if(USART3_RX_STA&0X8000)			//���յ�һ��������
		{
			
 			reclen=USART3_RX_STA&0X7FFF;	//�õ����ݳ���
		  	USART3_RX_BUF[reclen]=0;	 	//���������

				if(strcmp(USART3_RX_BUF,"0")==0)//strcmp������string compare(�ַ����Ƚ�)����д�����ڱȽ������ַ��������ݱȽϽ������������
				                               	//������ʽΪstrcmp(str1,str2)����str1=str2���򷵻��㣻��str1<str2���򷵻ظ�������str1>str2���򷵻�������
				{
				LED0=!LED0;	//��LED
				}
				
// 			 OLED_P6x8Str(2,4,USART3_RX_BUF,0);//��ʾ���յ�������
				printf("%s",USART3_RX_BUF);
			u3_printf("%s\r\n",USART3_RX_BUF);//���ظ����Ͷ˷�������
			
 			USART3_RX_STA=0;	 
		}	 															     
}
