#include "RD.h"


//初始化PD13和PD14为输出口.并使能这个IO口的时钟		    
//LED IO初始化
void RD_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PD端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				 //LED1-->PB.13,LED3-->PB.14  端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOD.13,GPIO.14

}
