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
		OLED_Fill(0xFF);//È«ÆÁµãÁÁ
		DelayS(2);
		OLED_Fill(0x00);//È«ÆÁÃð
		DelayS(2);
		for(i=0;i<5;i++)
		{
			OLED_ShowCN(22+i*16,0,i);//²âÊÔÏÔÊ¾ÖÐÎÄ
		}
		DelayS(2);
		OLED_ShowStr(0,3,"HelTec Automation",1);//²âÊÔ6*8×Ö·û
		OLED_ShowStr(0,4,"Hello Tech",2);				//²âÊÔ8*16×Ö·û
		DelayS(2);
		OLED_CLS();//ÇåÆÁ
		OLED_OFF();//²âÊÔOLEDÐÝÃß
		DelayS(2);
		OLED_ON();//²âÊÔOLEDÐÝÃßºó»½ÐÑ
		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//²âÊÔBMPÎ»Í¼ÏÔÊ¾
		DelayS(2);
	}
	
}
