#include"motor.h"
void IN12_Init(void)
{ 
	GPIO_InitTypeDef GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能PORTB时钟

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_14|GPIO_Pin_15;//IN0 IN1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //设置成上拉输出
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
  GPIO_ResetBits(GPIOB,GPIO_Pin_14);
  GPIO_ResetBits(GPIOB,GPIO_Pin_15);	
 }
