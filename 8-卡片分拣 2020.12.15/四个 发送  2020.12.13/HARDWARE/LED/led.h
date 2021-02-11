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
////////////////////////////////////////////////////////////////////////////////// 
#define LED0 PBout(5)// PB5
#define LED1 PEout(5)// Pe5          系统运行指示灯
#define led_switch PAin(4)// PA4	   光电检测开关
#define led_switch2 PAin(5)// PA5	   光电检测开关2
#define led_switch3 PAin(7)// PA7	   光电检测开关3
#define led_switch4 PAin(8)// PA8	   光电检测开关4
#define belt PAout(6)// PA6          传送带控制口
void LED_Init(void);//初始化

		 				    
#endif
