#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "hc05.h"
#include "usart3.h"			 	 
#include "string.h"	   
#include "usmart.h"	
#include "oled.h"
#include "HX711.h"
 
 /************************************************
 ��չʵ��1��ALIENTEK STM32F103������ 
 ATK-HC05��������ģ��ʵ��-�⺯���汾  
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

 int main(void)
 {	 
	vu8             key = 0;		
	u8		           t	= 0; 
	u8               key_set0=0,key_set1=0,key_set2=0;
	u16 xy;
	u8 sendmask=0;
	u8 sendcnt=0;
	u8 sendbuf[20];	  
	u8 reclen=0;  	
	 
	unsigned long	shiwu	= 0;
	unsigned long	fuwei	= 0;   
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(9600);	        //���ڳ�ʼ��Ϊ9600
	LED_Init();				//��ʼ����LED���ӵ�Ӳ���ӿ�
	KEY_Init();				//��ʼ������
	usmart_dev.init(72); 	//��ʼ��USMART		
	Init_HX711pin();
	OLED_Init();              //oled��Ļ��ʼ��
	OLED_P8x16Str(3,0,"ready",0);
	Get_Maopi();				      //��ëƤ����
	delay_ms(1000);
	Get_Maopi();				      //���»�ȡëƤ����
	HC05_Init(); 		//��ʼ��ATK-HC05ģ��  
	USART3_RX_STA=0;
 	while(1) 
	{		
		key=KEY_Scan(0);	//�õ���ֵ
		switch (key)
		{
			case KEY0_PRES:
			OLED_P6x8Str(120,7,"0",1);  //ȷ��/���ͼ�
			key_set0=1;
			break;
			case KEY1_PRES:        //ʵʱ��ʾ����ģʽ  
			OLED_P6x8Str(120,7,"1",1);
			key_set1=1;
			key_set2=0;
			Get_Maopi();		      //��ʼ��ȥƤ
			break;
			case KEY2_PRES:        //����ģʽ	
			OLED_P6x8Str(120,7,"2",1);
			key_set2=1;
			key_set1=0;
			Get_Maopi();		      //��ʼ��ȥƤ
			break;
		}
		if(key_set1==1)     //ʵʱ��ʾ����ģʽ
		{
//			 
//**********************��ȡ����***********************			
			delay_ms( 10 );
			if ( t++ > 10 )
			{
				t = 0;
				/* ˢ����������ʾ */
				Get_Weight();
				if ( Flag_Error == 0 )
				{
					shiwu = Weight_Shiwu -fuwei ; /* ��λ��g */	    						
				}else
				{
					shiwu=0;//��ȡ�쳣 ��һ�㲻���쳣
				}

//*************************��ʾ**************************
				Oled_Printf_U16(50,0,(int)shiwu,1);
				OLED_P8x16Str(100,0,"g",1);
				OLED_P8x16Str(3,0,"weight",1);
				printf("������ = %d g\r\n",(int)shiwu); //��ӡ 			
			}
		}
		if(key_set2==1)     //����ģʽ	
		{
			OLED_P8x16Str(3,0,"blue  ",1);
			delay_ms( 10 );
			if ( t++ > 10 )
			{
				t = 0;
				/* ˢ����������ʾ */
				Get_Weight();
				if ( Flag_Error == 0 )
				{
					shiwu = Weight_Shiwu -fuwei ; /* ��λ��g */	    						
				}else
				{
					shiwu=0;//��ȡ�쳣 ��һ�㲻���쳣
				}

//*************************��ʾ**************************
				Oled_Printf_U16(50,0,(int)shiwu,1);
				OLED_P8x16Str(100,0,"g",1);
				printf("������ = %d g\r\n",(int)shiwu); //��ӡ 			
			}
      if(key_set0==1)        //����
			{
				u3_printf("%d\r\n",shiwu);    //��ʾ����
				u3_printf("%s\r\n","g");      //���ͷ���
				key_set0=0;
		  }
		}			
	}
}
