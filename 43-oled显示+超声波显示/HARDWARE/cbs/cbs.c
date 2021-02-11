#include "cbs.h"
#include "stm32f10x.h"
#include "delay.h"

void Cbs_Init(void)    
{
	
	GPIO_InitTypeDef GPIO_InitSTR;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitSTR.GPIO_Mode=GPIO_Mode_Out_PP;    //trig �� 
	GPIO_InitSTR.GPIO_Pin=GPIO_Pin_3;
	GPIO_InitSTR.GPIO_Speed=GPIO_Speed_50MHz; 
	GPIO_Init(GPIOD,&GPIO_InitSTR);
	GPIO_ResetBits(GPIOD,GPIO_Pin_3);
	
	GPIO_InitSTR.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitSTR.GPIO_Pin=GPIO_Pin_0;								//echo �� 
	GPIO_Init(GPIOA,&GPIO_InitSTR);
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);	
	
}
void Start_Measure(void)
{
	GPIO_SetBits(GPIOD,GPIO_Pin_3);     //���ʱ�����ȸ�TRIG������10us�ĸߵ�ƽ
 	delay_ms(10);
	GPIO_ResetBits(GPIOD,GPIO_Pin_3);
}

