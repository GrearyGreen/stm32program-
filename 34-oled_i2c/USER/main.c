#include "stm32f10x.h"
#include "oled.h"
#include "string.h"
#include "menu.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "funcation.h"
#include "usart.h"
//1:ѡ��״̬��0��δѡ��״̬

void show(u8 souyin1,u8 suoyin2,u8 clickflag);

int main(void)
{	
	s8 i=0,j=0;
	u8 key_velue,click = 0;
	delay_init();													//����дʲô��������Ҫ�������ӳ�
	OLED_Init();
	uart_init(115200);												//���Դ��ڲ�����
	KEY_Init();
	LED_Init();
//	OLED_Show16x16(0*16,0,1,0);
//	OLED_Show16x16(1*16,0,2,0);
//	OLED_Show16x16(0*16,2,3,0);
//	OLED_Show16x16(1*16,2,4,0);
//	OLED_Show16x16(4*16,0,5,0);
//	OLED_Show16x16(5*16,0,6,0);
//	OLED_Show16x16(6*16,0,7,0);
//	OLED_Show16x16(7*16,0,15,0);
//	OLED_Show16x16(4*16,0,1,0);
	menumain();
	while(1)
	{
		key_velue = KEY_Scan(0);
		switch(key_velue)
		{
			case 1://����
				i--;
				if(i == -1)
				{
					i = 0;
				}
				break;
			case 2://��
				j++;
				if(j == 3)
				{
					j = 0;
				}
				break;
			case 3://ȷ��
				i++;
				if(i == 1)
				{
					i = 0;
				}
				click = 1;//�ǽ�����Ŀ¼����ȷ��ִ�г���
				break;
			case 4://��
				j--;
				if(j == -1)
				{
					j = 0;
				}
				break;
		}
		if(key_velue != 0)
			show(i,j,click);
	}
}

void show(u8 souyin1,u8 suoyin2,u8 clickflag)
{
	switch(souyin1)
	{
		case 0:
			switch(suoyin2)
			{
				case 0:
					menufirst();//��ʾѡ���һ��
					if(clickflag == 1)//���ȷ����ʵ���书��
					{
						fun1();
						clickflag = 0;
					}
					break;
				case 1:
					menusecond();//��ʾѡ��ڶ���
					if(clickflag == 1)
					{
						fun2();
						clickflag = 0;
					}
					break;
				case 2:
					menuthird();//��ʾѡ�������
					if(clickflag == 1)
					{
						fun3();
						clickflag = 0;
					}
					break;
			}
			break;
	}
}
