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


#define K4 PEin(4)   	//PE4
#define K3 PEin(3)	//PE3 
#define K2 PEin(2)	//PE2


//#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)//��ȡ����0
//#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)//��ȡ����1
//#define KEY2  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//��ȡ����2 
//#define KEY3  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)
//#define KEY4  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)
//#define KEY5  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)
//#define KEY6  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_4)
//#define KEY7  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_5)
//#define KEY8  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_6)
//#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//��ȡ����3(WK_UP) 

 

//#define KEY0_PRES 	1	//KEY0����
//#define KEY1_PRES	  2	//KEY1����
//#define KEY2_PRES	  3	//KEY2����
//#define KEY3_PRES	  4	//KEY2����
//#define KEY4_PRES	  5	//KEY2����
//#define KEY5_PRES	  6	//KEY2����
//#define KEY6_PRES	  7	//KEY2����
//#define KEY7_PRES	  8	//KEY2����
//#define KEY8_PRES   9
//#define NOKEY       11
//#define WKUP_PRES   10	//KEY_UP����(��WK_UP/KEY_UP)

#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)//��ȡ����0
#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//��ȡ����1
#define KEY2  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)//��ȡ����2 


 

//#define KEY0_PRES 	1	//KEY0����
//#define KEY1_PRES	2	//KEY1����
//#define KEY2_PRES	3	//KEY2����




void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8);  	//����ɨ�躯��		
void EXTIX_Init(void);//�ⲿ�жϳ�ʼ��	
#endif
