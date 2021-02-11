#include "move.h"
#include "sys.h"
#include "delay.h"
#include "oled.h"


void MOVE_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOF, ENABLE);	 //使能PB,PE端口时钟
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;	//PC6-7为电机脉冲输出脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_Init(GPIOF, &GPIO_InitStructure);	
	GPIO_SetBits(GPIOF,GPIO_Pin_12);
	
  GPIO_SetBits(GPIOC,GPIO_Pin_6);
  GPIO_SetBits(GPIOC,GPIO_Pin_7);
  GPIO_ResetBits(GPIOC,GPIO_Pin_8);
  GPIO_SetBits(GPIOC,GPIO_Pin_9);	
	
}


u8 EN = 0;
void goForward(void)
{
	DIRR = 1;
	DIRL = 1;
	EN = 1;
	OLED_P8x16Str(2,2,"UP   ",0);
}


void goBack(void)
{
	DIRR = 0;
	DIRL = 0;
	EN = 1;
	OLED_P8x16Str(2,2,"DOWN ",0);
}

void turnLeft(void)
{
	DIRR = 1;
	DIRL = 0;
	EN = 1;
	OLED_P8x16Str(2,2,"LEFT ",0);
}


void turnRight(void)
{
	DIRR = 0;
	DIRL = 1;
	EN = 1;
	OLED_P8x16Str(2,2,"RIGHT",0);
}



void stop(void)
{
	EN = 0;
	OLED_P8x16Str(2,2,"STOP ",0);
}


void speedUp(void)
{
	if(TIM3->ARR >400 )
	{
		TIM3->CNT = 0;
		TIM3->ARR -= 200;
	}
	OLED_P8x16Str(2,4,"SPEEDUP  ",0);
}

void speedDown(void)
{
	if(TIM3->ARR < 1200)
	{
		TIM3->ARR += 200;
	}	
	OLED_P8x16Str(2,4,"SPEEDDOWN",0);
}

//void skill(void)
//{
//	if(SKI == 0) SKI = 1;
//	else SKI = 0;
//		
//}



