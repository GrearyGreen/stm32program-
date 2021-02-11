#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "stm32f10x.h"
#include "OLED_I2C.h"
#include "ds18b20.h"
#include "cbs.h"


 
/************************************************
 ALIENTEKս��STM32������ʵ��1
 �����ʵ�� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
	extern u8  TIM5CH1_CAPTURE_STA;		//���벶��״̬		    				
extern u16	TIM5CH1_CAPTURE_VAL;	//���벶��ֵ
	
	int main (void)
{	 
	u32 temper=0;
	float distance;
	unsigned char i;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //ʱ������
  uart_init(115200);//���ڳ�ʼ���������ǲ����ʣ�
	delay_init();
	//������
 
		Cbs_Init();   //������ģ���ʼ��
	TIM5_Cap_Init(0XFFFF,72-1);	//��1Mhz��Ƶ�ʼ���
	DS18B20_Init();	//�¶�ģ���ʼ��
	
	LED_Init();//led��ʼ��
	
	I2C_Configuration();  //��ʼ��olediic

  OLED_Init();       //��ʼ��oledģ��,һ��Ҫ����ȥ����ŻṤ��
	
	//��ѭ��
	 OLED_CLS();//����
	while(1)
		{
			
//		  unsigned char temp[10];
			 unsigned char dis[10];
//			
//			float tem=DS18B20_Get_Temp()/10.0;
//			LED0=!LED0;
//			delay_ms(2000);
//			
	
//			
//	 //   OLED_CLS();//����
//			for(i=0;i<2;i++)
//		 {
//			OLED_ShowCN(i*16,0,i);//��ʾ��������
//	   }
//		

//		 sprintf((char *)temp,"%0.6f",tem);
//		 OLED_ShowStr(0,3,temp,1);
//     printf("DS18B20��ȡ�¶�ֵΪ%f\n\r",tem);
//			

//      delay_ms(1000); //��ʱ
//		 	OLED_Fill(0xFF);//ȫ������
//		 delay_ms(1000); //��ʱ
//		OLED_Fill(0x00);//ȫ����
		 delay_ms(1000); //��ʱ
		 Start_Measure();    //��ʼ���

			 
			for(i=0;i<2;i++)
		 {
			OLED_ShowCN(i*16,0,i);//��ʾ��������
	   }
		 	if(TIM5CH1_CAPTURE_STA&0X80)//�ɹ�������һ��������
		{
			temper=TIM5CH1_CAPTURE_STA&0X3F;
			temper*=65536;//���ʱ���ܺ�
			temper+=TIM5CH1_CAPTURE_VAL;//�õ��ܵĸߵ�ƽʱ��
			printf("HIGH:%d us    ",temper);//��ӡ�ܵĸߵ�ƽʱ��
			TIM5CH1_CAPTURE_STA=0;//������һ�β���
			distance = (float)temper/1000000*340/2;
			printf("DISTANCE:%f m\r\n",distance);//��ӡ����
		
			
			sprintf((char *)dis,"%0.6f",distance);
		 OLED_ShowStr(0,3,dis,1);
     printf("����Ϊ%f\n\r",distance);
		}
			
			
		}

		 
}

void FloatToUint8(uint8_t * char_array,float data)
{
    uint8_t i;
    for(i=0;i<4;i++)
    {
        char_array[i] = ((uint8_t*)(&data))[i];
    }
}


// int main(void)
// {	
//	unsigned char i;

//	delay_init();
//	I2C_Configuration();  //��ʼ��olediic
//	OLED_Init();       //��ʼ��oledģ��
//	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�



//	while(1)
//	{

//		for(i=0;i<2;i++)
//		{
//			OLED_ShowCN(i*16,0,i);//������ʾ����
//		}
//		delay_ms(20000);
//		
//		for(i=0;i<5;i++)
//		{
//		
//		OLED_ShowStr(0,3,"",1);//����6*8�ַ�
//		}
//		
//		OLED_ShowStr(0,4,"Hello Tech",2);				//����8*16�ַ�
//		delay_ms(20000);
//		OLED_CLS();//����
//		OLED_OFF();//����OLED����
//		delay_ms(20000);
//		OLED_ON();//����OLED���ߺ���
//	
//	} 
// }
//	delay_init();	    //��ʱ������ʼ��	  
//	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
//	while(1)
//	{
//		LED0=0;
//		LED1=1;
//		delay_ms(300);	 //��ʱ300ms
//		LED0=1;
//		LED1=0;
//		delay_ms(300);	//��ʱ300ms
//	}



 /**
 *****************����ע�ӵĴ�����ͨ�����ÿ⺯����ʵ��IO���Ƶķ���*****************************************

 unsigned char i;
	extern const unsigned char BMP1[];
	
	delay_init();
	I2C_Configuration();
	OLED_Init();
	
	while(1)
	{
		OLED_Fill(0xFF);//ȫ������
		OLED_Fill(0x00);//ȫ����
		for(i=0;i<5;i++)
		{
			OLED_ShowCN(22+i*16,0,i);//������ʾ����
		}
		delay_ms(20000);
		OLED_ShowStr(0,3,"HelTec Automation",1);//����6*8�ַ�
		OLED_ShowStr(0,4,"Hello Tech",2);				//����8*16�ַ�
		delay_ms(20000);
		OLED_CLS();//����
		OLED_OFF();//����OLED����
		delay_ms(20000);
		OLED_ON();//����OLED���ߺ���
		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//����BMPλͼ��ʾ
		delay_ms(20000);
	}
 ****************************************************************************************************
 ***/
 


