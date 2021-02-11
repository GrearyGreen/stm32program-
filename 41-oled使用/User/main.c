#include "stm32f10x.h"
#include "OLED_I2C.h"
#include "delay.h"

int main()
{
	
	unsigned char i;
	extern const unsigned char BMP1[];
	
	DelayInit();
	I2C_Configuration();
	OLED_Init();
	
	while(1)
	{
		OLED_Fill(0xFF);//全屏点亮
		DelayS(2);
		OLED_Fill(0x00);//全屏灭
		DelayS(2);
		for(i=0;i<3;i++)
		{
			 OLED_ShowCN(22+i*16,0,i);//测试显示中文  22指的是从左往右数22格开始显示小蓝点，0指的是从上往下第0个开始显示，后面的i是第i个数字
		}
		DelayS(2);
//		OLED_ShowStr(0,3,"wty hello",1);//测试6*8字符
//		OLED_ShowStr(0,4,"Hello Tech",2);				//测试8*16字符
		DelayS(2);
		OLED_CLS();//清屏
		OLED_OFF();//测试OLED休眠
		DelayS(2);
		OLED_ON();//测试OLED休眠后唤醒
//		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//测试BMP位图显示
//		DelayS(2);
	}
	
}
