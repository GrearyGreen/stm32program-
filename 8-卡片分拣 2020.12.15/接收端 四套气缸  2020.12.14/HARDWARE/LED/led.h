#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
///////////////////////////////////////////////////////////////////////////////// 
#define LED0 PAout(3)// PE0   ����1
#define LED1 PAout(1)// PA1 	����2
#define LED2 PAout(2)// PA2	  ����3
#define LED3 PEout(3)// PE3	   ����4
#define LED4 PEout(4)// PE4	   ����1
#define LED5 PEout(5)// PE5	   ����2
#define LED6 PEout(6)// PE6	   ����3
#define LED7 PCout(13)// PC13	   ����4
//#define LED8 PFout(1)//  ����1
//#define LED9 PFout(2)//  ����2
//#define LED10 PFout(3)//  ����3
//#define LED11 PFout(4)//  ����4
//#define LED12 PFout(5)//  ����5
//#define LED13 PFout(6)//  ����6
//#define LED14 PFout(7)// ����7	
//#define LED15 PFout(8)// ����8

void LED_Init(void);//��ʼ��

		 				    
#endif
