#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
///////////////////////////////////////////////////////////////////////////////// 
#define LED0 PAout(3)// PE0   气缸1
#define LED1 PAout(1)// PA1 	气缸2
#define LED2 PAout(2)// PA2	  气缸3
#define LED3 PEout(3)// PE3	   气缸4
#define LED4 PEout(4)// PE4	   气缸1
#define LED5 PEout(5)// PE5	   气缸2
#define LED6 PEout(6)// PE6	   气缸3
#define LED7 PCout(13)// PC13	   气缸4
//#define LED8 PFout(1)//  吸盘1
//#define LED9 PFout(2)//  吸盘2
//#define LED10 PFout(3)//  吸盘3
//#define LED11 PFout(4)//  吸盘4
//#define LED12 PFout(5)//  吸盘5
//#define LED13 PFout(6)//  吸盘6
//#define LED14 PFout(7)// 吸盘7	
//#define LED15 PFout(8)// 吸盘8

void LED_Init(void);//初始化

		 				    
#endif
