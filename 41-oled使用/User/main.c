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
		OLED_Fill(0xFF);//ȫ������
		DelayS(2);
		OLED_Fill(0x00);//ȫ����
		DelayS(2);
		for(i=0;i<3;i++)
		{
			 OLED_ShowCN(22+i*16,0,i);//������ʾ����  22ָ���Ǵ���������22��ʼ��ʾС���㣬0ָ���Ǵ������µ�0����ʼ��ʾ�������i�ǵ�i������
		}
		DelayS(2);
//		OLED_ShowStr(0,3,"wty hello",1);//����6*8�ַ�
//		OLED_ShowStr(0,4,"Hello Tech",2);				//����8*16�ַ�
		DelayS(2);
		OLED_CLS();//����
		OLED_OFF();//����OLED����
		DelayS(2);
		OLED_ON();//����OLED���ߺ���
//		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//����BMPλͼ��ʾ
//		DelayS(2);
	}
	
}
