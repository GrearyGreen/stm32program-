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


#define Upper_KEY      PBin(6)   	
#define Left_KEY       PBin(7)	
#define Right_KEY      PBin(8)   	
#define Lower_KEY      PBin(9)
#define Determine_KEY  PCin(13)   	
#define Return_KEY     PCin(14)
#define ALL (key==Upper||key==Left||key==Right||key==Lower||key==Determine||key==Return)

//#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)//读取按键0
//#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//读取按键1
//#define KEY2  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)//读取按键2 
//#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//读取按键3(WK_UP) 

 #define Upper      2  //上
 #define Left       3  //左
 #define Right      4  //右 
 #define Lower      5  //下
 #define Determine  6  //确定
 #define Return     7  //返回




void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8 mode);  	//按键扫描函数					    
#endif
