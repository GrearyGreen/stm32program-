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
////////////////////////////////////////////////////////////////////////////////// 
#define LED0 PBout(5)// PB5
#define LED1 PEout(5)// Pe5          ϵͳ����ָʾ��
#define led_switch PAin(4)// PA4	   ����⿪��
#define led_switch2 PAin(5)// PA5	   ����⿪��2
#define led_switch3 PAin(7)// PA7	   ����⿪��3
#define led_switch4 PAin(8)// PA8	   ����⿪��4
#define belt PAout(6)// PA6          ���ʹ����ƿ�
void LED_Init(void);//��ʼ��

		 				    
#endif
