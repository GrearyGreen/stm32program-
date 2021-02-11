#include "bjdj.h"
#include "delay.h"

#define uint unsigned int
	
//�����������ת����1
//uint16_t phasecw[4] ={0x0080,0x4000,0x2000,0x1000};// D-C-B-A   
//uint16_t phaseccw[4]={0x1000,0x2000,0x4000,0x8000};// A-B-C-D.

//�����������ת����2
//uint16_t phasecw1[4] ={0x0800,0x0400,0x0200,0x0100};// D-C-B-A   
//uint16_t phaseccw1[4]={0x0100,0x0200,0x0400,0x0800};// A-B-C-D.	
void Delay_xms(uint x)
{
 uint i,j;
 for(i=0;i<x;i++)
  for(j=0;j<112;j++);
}

void Moto_Init(void)
{
	//���1
 GPIO_InitTypeDef GPIO_InitStructure;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6 |GPIO_Pin_7 ;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA,&GPIO_InitStructure);
 GPIO_ResetBits(GPIOA,GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6 |GPIO_Pin_7 );
// IN4: PC9   d
// IN3: PC8   c
// IN2: PC7   b
// IN1: PC6   a
	
	//���2
// RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);
// GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 ;
// GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
// GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
// GPIO_Init(GPIOG,&GPIO_InitStructure);
// GPIO_ResetBits(GPIOG,GPIO_Pin_8 | GPIO_Pin_9 |GPIO_Pin_10 |GPIO_Pin_11 );
// IN4: PG11  d
// IN3: PG10  c
// IN2: PG9   b
// IN1: PG8   a
}

//void Motorcw(int speed)  
//{  
//    int w;  
//  
//    for(w=0;w<4;w++)  
//    {  
////        GPIO_Write(GPIOA,phasecw[w]);  
//        delay_ms(speed); 
//    }  
//}

//void Motorcw1(int speed)  
//{  
//    uint8_t i;  
//  
//    for(i=0;i<4;i++)  
//    {  
////        GPIO_Write(GPIOG,phasecw1[i]);  
//        Delay_xms(speed);  
//    }  
//}

//void Motorccw(int speed)  
//{  
//    int w;  
//    for(w=0;w<4;w++)  
//    {  
//        GPIO_Write(GPIOA,phaseccw[w]);  
//        delay_ms(speed);  
//    }  
//}

//void Motorccw1(int speed)  
//{  
//    uint8_t i;  
//  
//    for(i=0;i<4;i++)  
//    {  
//        GPIO_Write(GPIOG,phaseccw1[i]);  
//        Delay_xms(speed);  
//    }  
//}

void MotorStop(void)  
{  
//    GPIO_Write(GPIOC,0x0000);  
	GPIO_ResetBits(GPIOA,GPIO_Pin_4 | GPIO_Pin_5 |GPIO_Pin_6 |GPIO_Pin_7 );
}

//void MotorStop1(void)  
//{  
//    GPIO_Write(GPIOG,0x0000);  
//}

//����   *һ������*   *�����*  ת0.08789�ȣ����ʵת0.08789*64=5.625�ȣ�����������Ϊ5.625�ȡ���ת��A-B-C-DΪ  *8������*  ����0.08789*8=0.70312�ȡ�����A-B-C-DΪһ�����ڣ���jΪ��Ҫ��ת��angle�Ƕ��������������
void Motorcw_angle(int angle,int speed)
{
	int i,j;
	j=(int)(angle/0.70312);
	for(i=0;i<j;i++)
	{
//				Motorcw(speed);
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
    GPIO_ResetBits(GPIOA,GPIO_Pin_5);
    GPIO_ResetBits(GPIOA,GPIO_Pin_6);
    GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		delay_ms(speed);
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
    GPIO_SetBits(GPIOA,GPIO_Pin_5);
    GPIO_ResetBits(GPIOA,GPIO_Pin_6);
    GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		delay_ms(speed);
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
    GPIO_ResetBits(GPIOA,GPIO_Pin_5);
    GPIO_SetBits(GPIOA,GPIO_Pin_6);
    GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		delay_ms(speed);
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
    GPIO_ResetBits(GPIOA,GPIO_Pin_5);
    GPIO_ResetBits(GPIOA,GPIO_Pin_6);
    GPIO_SetBits(GPIOA,GPIO_Pin_7);
		delay_ms(speed);
	}
	MotorStop();
}

//void Motorcw_angle1(int angle,int speed)
//{
//	int i,j;
//	j=(int)(angle/0.70312);
//	for(i=0;i<j;i++)
//	{
//		Motorcw1(speed);
//	}
//	MotorStop1();
//}

void Motorccw_angle(int angle,int speed)
{
	int i,j;
	j=(int)(angle/0.70312);
	for(i=0;i<j;i++)
	{
//		Motorccw(speed);
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
    GPIO_ResetBits(GPIOA,GPIO_Pin_5);
    GPIO_ResetBits(GPIOA,GPIO_Pin_6);
    GPIO_SetBits(GPIOA,GPIO_Pin_7);
		delay_ms(speed);
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
    GPIO_ResetBits(GPIOA,GPIO_Pin_5);
    GPIO_SetBits(GPIOA,GPIO_Pin_6);
    GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		delay_ms(speed);
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
    GPIO_SetBits(GPIOA,GPIO_Pin_5);
    GPIO_ResetBits(GPIOA,GPIO_Pin_6);
    GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		delay_ms(speed);
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
    GPIO_ResetBits(GPIOA,GPIO_Pin_5);
    GPIO_ResetBits(GPIOA,GPIO_Pin_6);
    GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		delay_ms(speed);
	}
	MotorStop();
}

//void Motorccw_angle1(int angle,int speed)
//{
//	int i,j;
//	j=(int)(angle/0.70312);
//	for(i=0;i<j;i++)
//	{
//		Motorccw1(speed);
//	}
//}
