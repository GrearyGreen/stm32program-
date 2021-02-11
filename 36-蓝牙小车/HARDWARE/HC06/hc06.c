#include "delay.h" 			 
#include "usart.h" 			 
#include "usart3.h" 			 
#include "hc06.h" 
#include "led.h" 
#include "string.h"	 
#include "math.h"
#include  "oled.h"
#include "L29.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32������
//ATK-HC05����ģ����������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2015/3/29
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//********************************************************************************
//V1.1 20140329
//�޸�LED�����ӣ�ԭ����PC5����ΪPA4���Լ���MiniSTM32������V3.0									  
////////////////////////////////////////////////////////////////////////////////// 	   

//��ʼ��ATK-HC06ģ��
//����ֵ:0,�ɹ�;1,ʧ��.
extern	u16 PWM1;
extern int t1,t2;
void HC06_Init(void)
{
	usart3_init(9600);	//��ʼ������2Ϊ:9600,������.//������115200����Ϊģ��AT������
}	 
void HC06_receive(void)                 //���պ��� 
{  	
	u8 reclen=0;
	if(USART3_RX_STA&0X8000)			//���յ�һ��������
	{
			
 		reclen=USART3_RX_STA&0X7FFF;	//�õ����ݳ���
		USART3_RX_BUF[reclen]=0;	 	//���������

		if(strcmp(USART3_RX_BUF,"0")==0)//strcmp������string compare(�ַ����Ƚ�)����д�����ڱȽ������ַ��������ݱȽϽ������������
				                               	//������ʽΪstrcmp(str1,str2)����str1=str2���򷵻��㣻��str1<str2���򷵻ظ�������str1>str2���򷵻�������
		{
			MOTSET_front();	//��LED
		}
		if(strcmp(USART3_RX_BUF,"1")==0)
		{	
			MOTSET_left();	
	    }
		if(strcmp(USART3_RX_BUF,"2")==0)
		{	
			MOTSET_right();	
	    }
		if(strcmp(USART3_RX_BUF,"3")==0)
		{	
			MOTSET_back();
	    }
		if(strcmp(USART3_RX_BUF,"4")==0)
		{	
			MOTSET_stop();
	    }
		if(strcmp(USART3_RX_BUF,"5")==0)
		{	
			PWM1=PWM1+10;
	    }
		if(strcmp(USART3_RX_BUF,"6")==0)
		{	
			PWM1=PWM1-10;
	    }
//        if(strcmp(USART3_RX_BUF,"4")==0)
//				{	
//				t2=t2+10;	
//	      }
//				if(strcmp(USART3_RX_BUF,"5")==0)
//				{	
//				t2=t2-10;	
//	      }
//				if(strcmp(USART3_RX_BUF,"6")==0)
//				{	
//				MOTSET_stop();
//	      }
 		OLED_P6x8Str(2,4,USART3_RX_BUF,0);//��ʾ���յ�������
		printf("%s",USART3_RX_BUF);
		u3_printf("%s\r\n",USART3_RX_BUF);//���ظ����Ͷ˷�������
			
 		USART3_RX_STA=0;	 
	}	 															     
}








