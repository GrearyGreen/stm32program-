#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	 


//#define KEY0 PEin(4)   	//PE4
//#define KEY1 PEin(3)	//PE3 
//#define KEY2 PEin(2)	//PE2
//#define WK_UP PAin(0)	//PA0  WK_UP

#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0)//��ȡ����0
#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)//��ȡ����1
#define KEY2  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)//��ȡ����2 
//#define KEY3  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//��ȡ����3 
//#define KEY4  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)//��ȡ����4
//#define KEY5  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5)//��ȡ����5 
//#define KEY6  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_6)//��ȡ����6 
//#define KEY7  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)//��ȡ����7 
//#define KEY8  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)//��ȡ����8
//#define KEY9  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)//��ȡ����9 
//#define KEY10  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)//��ȡ����10
//#define KEY11  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)//��ȡ����11
//#define KEY12  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)//��ȡ����12
//#define KEY13  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)//��ȡ����13


#define KEY0_PRES 	1	//KEY0����
#define KEY1_PRES 	2	//KEY1����
#define KEY2_PRES 	3	//KEY2����
//#define KEY3_PRES	  4	//KEY2����
//#define KEY4_PRES 	5	//KEY0����
//#define KEY5_PRES 	6	//KEY1����
//#define KEY6_PRES 	7	//KEY2����
//#define KEY7_PRES	  8	//KEY2����
//#define KEY8_PRES 	9	//KEY2����
//#define KEY9_PRES	  10	//KEY2����
//#define KEY10_PRES	  11	//KEY2����
//#define KEY11_PRES 	12	//KEY2����
//#define KEY12_PRES	  13	//KEY2����
//#define KEY13_PRES	  14	//KEY2����

void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8);  	//����ɨ�躯��					    
#endif
