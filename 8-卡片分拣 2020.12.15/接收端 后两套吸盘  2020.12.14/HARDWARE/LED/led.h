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
#define sucker0 PAout(10)// PA0   ����0
#define sucker1 PAout(1)// PA1   ����1
#define sucker2 PAout(2)// PA2   ����2
#define sucker3 PAout(3)// PA3   ����3

#define sucker4 PAout(4)// PA4   ����4
#define sucker5 PAout(5)// PA5   ����5
#define sucker6 PAout(6)// PA6   ����6
#define sucker7 PAout(7)// PA7   ����7

void LED_Init(void);//��ʼ��

		 				    
#endif
