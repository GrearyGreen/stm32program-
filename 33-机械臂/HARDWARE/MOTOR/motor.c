#include"motor.h"
void IN12_Init(void)
{ 
	GPIO_InitTypeDef GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��PORTBʱ��

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_14|GPIO_Pin_15;//IN0 IN1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //���ó��������
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
  GPIO_ResetBits(GPIOB,GPIO_Pin_14);
  GPIO_ResetBits(GPIOB,GPIO_Pin_15);	
 }
