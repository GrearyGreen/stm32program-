#ifndef __KEY_H
#define __KEY_H	 
#include "stm32f10x.h"

#define KEY2  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)//¶ÁÈ¡°´¼ü2 

void KEY_Init(void);
u8 KEY_Scan(u8);

#endif
