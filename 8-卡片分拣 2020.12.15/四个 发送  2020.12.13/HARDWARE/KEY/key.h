#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//按键驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/3
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	 


#define K4 PEin(4)   	//PE4
#define K3 PEin(3)	//PE3 
#define K2 PEin(2)	//PE2


//#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)//读取按键0
//#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)//读取按键1
//#define KEY2  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//读取按键2 
//#define KEY3  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)
//#define KEY4  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)
//#define KEY5  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)
//#define KEY6  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_4)
//#define KEY7  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_5)
//#define KEY8  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_6)
//#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//读取按键3(WK_UP) 

 

//#define KEY0_PRES 	1	//KEY0按下
//#define KEY1_PRES	  2	//KEY1按下
//#define KEY2_PRES	  3	//KEY2按下
//#define KEY3_PRES	  4	//KEY2按下
//#define KEY4_PRES	  5	//KEY2按下
//#define KEY5_PRES	  6	//KEY2按下
//#define KEY6_PRES	  7	//KEY2按下
//#define KEY7_PRES	  8	//KEY2按下
//#define KEY8_PRES   9
//#define NOKEY       11
//#define WKUP_PRES   10	//KEY_UP按下(即WK_UP/KEY_UP)

#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)//读取按键0
#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//读取按键1
#define KEY2  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)//读取按键2 


 

//#define KEY0_PRES 	1	//KEY0按下
//#define KEY1_PRES	2	//KEY1按下
//#define KEY2_PRES	3	//KEY2按下




void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8);  	//按键扫描函数		
void EXTIX_Init(void);//外部中断初始化	
#endif
