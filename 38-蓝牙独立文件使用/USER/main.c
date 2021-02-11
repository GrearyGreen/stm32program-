#include "stm32f10x.h"
#include "oled.h"
#include "string.h"
#include "delay.h"
#include "usart.h"//���ڵ���
#include "usart3.h"//������Ҫ�Ĵ���
#include "hc05.h"
//#include "stdio.h"
//#include "stdlib.h"
//1:ѡ��״̬��0��δѡ��״̬
//����������USART3_RX_BUF�������ͨ����n = USART3_RX_BUF[x]����ȡ
//����������u3_printf("%d\r\n",num);���ֻ��˷�������

int main(void)
{
	delay_init();//�ӳٳ�ʼ��
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);//���ڵ��ԵĲ�����
	OLED_Init();//oled��ʼ��
	OLED_P8x16Str(2*16,2,"READAY",0);
	HC05_Init();//������ʼ��
	USART3_RX_STA=0;//�������գ���־��ʼ��
	u3_printf("ready\r\n");
	printf("ready\r\n");
	while(1)
	{
		u8 reclen=0;
		if(USART3_RX_STA&0X8000)			//���յ�һ��������
		{
			reclen=USART3_RX_STA&0X7FFF;	//�õ����ݳ���
			USART3_RX_BUF[reclen]=0;	 	//���������
			
			printf("%s\r\n",USART3_RX_BUF);
			
			OLED_Fill(0x00);				//����
//			if(strcmp(USART3_RX_BUF,"0")==0)
//			{
//				OLED_P6x8Str(32,2,"200",0);//��ʾ���յ�������
//			}
			OLED_P8x16Str(2*16,2,USART3_RX_BUF,0);
			u3_printf("I get %s\r\n",USART3_RX_BUF);
//		if(strcmp(USART3_RX_BUF,"0")==0)//strcmp������string compare(�ַ����Ƚ�)����д�����ڱȽ������ַ��������ݱȽϽ������������
//				                               	//������ʽΪstrcmp(str1,str2)����str1=str2���򷵻��㣻��str1<str2���򷵻ظ�������str1>str2���򷵻�������
//		{
//			printf("jiayou\r\n");	//��LED
//		}
//		if(strcmp(USART3_RX_BUF,"1")==0)
//		{	
//			MOTSET_left();
//			printf("jiayou\r\n");
//	    }
//		if(strcmp(USART3_RX_BUF,"2")==0)
//		{	
//			MOTSET_right();	
//	    }
//		if(strcmp(USART3_RX_BUF,"3")==0)
//		{	
//			MOTSET_back();
//	    }
//		if(strcmp(USART3_RX_BUF,"4")==0)
//		{	
//			MOTSET_stop();
//	    }
//		if(strcmp(USART3_RX_BUF,"5")==0)
//		{	
//			PWM1=PWM1+10;
//	    }
//		if(strcmp(USART3_RX_BUF,"6")==0)
//		{	
//			PWM1=PWM1-10;
//	    }
////        if(strcmp(USART3_RX_BUF,"4")==0)
////				{	
////				t2=t2+10;	
////	      }
////				if(strcmp(USART3_RX_BUF,"5")==0)
////				{	
////				t2=t2-10;	
////	      }
////				if(strcmp(USART3_RX_BUF,"6")==0)
////				{	
////				MOTSET_stop();
////	      }
//			OLED_CLS();
//			OLED_P6x8Str(32,2,USART3_RX_BUF,0);//��ʾ���յ�������
//		printf("%s",USART3_RX_BUF);
//		u3_printf("%s\r\n",USART3_RX_BUF);//���ظ����Ͷ˷�������
//			
			USART3_RX_STA=0;//���ܱ�־��ʼ��
		}
	}		
}
