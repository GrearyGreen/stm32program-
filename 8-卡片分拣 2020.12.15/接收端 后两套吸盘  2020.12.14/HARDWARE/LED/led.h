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
#define sucker0 PAout(10)// PA0   吸盘0
#define sucker1 PAout(1)// PA1   吸盘1
#define sucker2 PAout(2)// PA2   吸盘2
#define sucker3 PAout(3)// PA3   吸盘3

#define sucker4 PAout(4)// PA4   吸盘4
#define sucker5 PAout(5)// PA5   吸盘5
#define sucker6 PAout(6)// PA6   吸盘6
#define sucker7 PAout(7)// PA7   吸盘7

void LED_Init(void);//初始化

		 				    
#endif
