#include "stm32f10x.h"
#include "oled.h"
#include "string.h"
#include "menu.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "funcation.h"
#include "usart.h"
//1:选中状态，0：未选中状态

void show(u8 souyin1,u8 suoyin2,u8 clickflag);

int main(void)
{	
	s8 i=0,j=0;
	u8 key_velue,click = 0;
	delay_init();													//无论写什么函数，都要先声明延迟
	OLED_Init();
	uart_init(115200);												//调试串口波特率
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
			case 1://返回
				i--;
				if(i == -1)
				{
					i = 0;
				}
				break;
			case 2://下
				j++;
				if(j == 3)
				{
					j = 0;
				}
				break;
			case 3://确认
				i++;
				if(i == 1)
				{
					i = 0;
				}
				click = 1;//是进入子目录还是确认执行程序
				break;
			case 4://上
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
					menufirst();//显示选择第一项
					if(clickflag == 1)//如果确定后，实现其功能
					{
						fun1();
						clickflag = 0;
					}
					break;
				case 1:
					menusecond();//显示选择第二项
					if(clickflag == 1)
					{
						fun2();
						clickflag = 0;
					}
					break;
				case 2:
					menuthird();//显示选择第三项
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
