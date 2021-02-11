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
//	u8 current;//当前状态索引号
//	u8 up;//向上翻索引号
//	u8 down;//向下翻索引号
//	u8 enter;//确认索引号
//	void (*current_operation)(void);//函数指针
//}key_table;
//key_table code_table[10]=
//{
//    {0,0,0,1,(*fun10)},//第0层，显示Welcomem Use！！！！
//    
//    {1,4,2,5,(*fun1)},//第一层，显示【蓝牙模式】，寻迹模式，PWM调速模式,返回
//    {2,1,3,6,(*fun2)},//第一层，显示蓝牙模式，【寻迹模式】，PWM调速模式,返回
//    {3,2,4,7,(*fun3)},//第一层，显示蓝牙模式，寻迹模式，【PWM调速模式】,返回
//    {4,3,1,0,(*fun4)},//第一层，显示蓝牙模式，寻迹模式，PWM调速模式,【返回】

//	{5,5,5,1,(*fun5)},//第二层，蓝牙模式下显示"SuccessEnter！！！"(flagmode = 1)
//	{6,6,6,2,(*fun6)},//第二层，寻迹模式下显示"SuccessEnter！！！"(flagmode = 2)
//	{7,9,8,8,(*fun7)},//第二层，PWM模式下显示【PWML：】、PWMR：、返回  (flagmode = 3)       	
//	{8,7,9,9,(*fun8)},//第二层，PWM模式下显示PWML：、【PWMR：】、返回  
//	{9,8,7,4,(*fun9)}, //第二层，PWM模式下显示PWML：、PWMR：、【返回】  
//};
extern  u8 code_table[10];

int main(void)
{			 
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
	
	 KEY_Init();
 	LED_Init();			     //LED端口初始化

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


//超声波加舵机
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
