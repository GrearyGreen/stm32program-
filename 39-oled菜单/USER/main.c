#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "oled.h"
#include "fun.h"
//void KeyAction(u8 keycode);
extern u8 flagmode;
//u8 func_index=0;
//typedef struct
//{
//	u8 current;//��ǰ״̬������
//	u8 up;//���Ϸ�������
//	u8 down;//���·�������
//	u8 enter;//ȷ��������
//	void (*current_operation)(void);//����ָ��
//}key_table;
//key_table code_table[10]=
//{
//    {0,0,0,1,(*fun10)},//��0�㣬��ʾWelcomem Use��������
//    
//    {1,4,2,5,(*fun1)},//��һ�㣬��ʾ������ģʽ����Ѱ��ģʽ��PWM����ģʽ,����
//    {2,1,3,6,(*fun2)},//��һ�㣬��ʾ����ģʽ����Ѱ��ģʽ����PWM����ģʽ,����
//    {3,2,4,7,(*fun3)},//��һ�㣬��ʾ����ģʽ��Ѱ��ģʽ����PWM����ģʽ��,����
//    {4,3,1,0,(*fun4)},//��һ�㣬��ʾ����ģʽ��Ѱ��ģʽ��PWM����ģʽ,�����ء�

//	{5,5,5,1,(*fun5)},//�ڶ��㣬����ģʽ����ʾ"SuccessEnter������"(flagmode = 1)
//	{6,6,6,2,(*fun6)},//�ڶ��㣬Ѱ��ģʽ����ʾ"SuccessEnter������"(flagmode = 2)
//	{7,9,8,8,(*fun7)},//�ڶ��㣬PWMģʽ����ʾ��PWML������PWMR��������  (flagmode = 3)       	
//	{8,7,9,9,(*fun8)},//�ڶ��㣬PWMģʽ����ʾPWML������PWMR����������  
//	{9,8,7,4,(*fun9)}, //�ڶ��㣬PWMģʽ����ʾPWML����PWMR���������ء�  
//};
extern  u8 code_table[10];

int main(void)
{			 
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
	
	 KEY_Init();
 	LED_Init();			     //LED�˿ڳ�ʼ��

	OLED_Init();
	

   	while(1)
	{
//		HC06_receive();
//		
//		
//		
		
//        Oled_Printf_U16(20,1,angle1,0);
//		Oled_Printf_U16(20,0,angle2,0);
//		Oled_Printf_U16(2,2,speed,0);

 	
    display();
	switch(flagmode)
	{
		case 0 :
			
		break;
		case 1 :
			
		break;
		case 2 :
		
		break;
		
		
	}


//�������Ӷ��
////	TenDistance=0;
		
//    measure();
//				
//	if(distance<0.2)
//	 {
//	  flag_Forward=1;
//	  Turn_Angle(90);
//	  delay_ms(1000);
//	  measure();
//		if(distance<0.2)
//		{
//		 flag_Right=1;
//		 Turn_Angle(-90);
//		 delay_ms(1000);
//		 measure();
//		 if(distance<0.2)
//		 {
//			flag_Left=1;			
//		 }
//	    }
//	 }	
//     Turn_Angle(0);
//     delay_ms(1000);
		
	}	 
 }
