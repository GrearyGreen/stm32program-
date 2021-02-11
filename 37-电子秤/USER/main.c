#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "hc05.h"
#include "usart3.h"			 	 
#include "string.h"	   
#include "usmart.h"	
#include "oled.h"
#include "HX711.h"
 
 /************************************************
 扩展实验1：ALIENTEK STM32F103开发板 
 ATK-HC05蓝牙串口模块实验-库函数版本  
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

 int main(void)
 {	 
	vu8             key = 0;		
	u8		           t	= 0; 
	u8               key_set0=0,key_set1=0,key_set2=0;
	u16 xy;
	u8 sendmask=0;
	u8 sendcnt=0;
	u8 sendbuf[20];	  
	u8 reclen=0;  	
	 
	unsigned long	shiwu	= 0;
	unsigned long	fuwei	= 0;   
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(9600);	        //串口初始化为9600
	LED_Init();				//初始化与LED连接的硬件接口
	KEY_Init();				//初始化按键
	usmart_dev.init(72); 	//初始化USMART		
	Init_HX711pin();
	OLED_Init();              //oled屏幕初始化
	OLED_P8x16Str(3,0,"ready",0);
	Get_Maopi();				      //称毛皮重量
	delay_ms(1000);
	Get_Maopi();				      //重新获取毛皮重量
	HC05_Init(); 		//初始化ATK-HC05模块  
	USART3_RX_STA=0;
 	while(1) 
	{		
		key=KEY_Scan(0);	//得到键值
		switch (key)
		{
			case KEY0_PRES:
			OLED_P6x8Str(120,7,"0",1);  //确定/发送键
			key_set0=1;
			break;
			case KEY1_PRES:        //实时显示重量模式  
			OLED_P6x8Str(120,7,"1",1);
			key_set1=1;
			key_set2=0;
			Get_Maopi();		      //初始化去皮
			break;
			case KEY2_PRES:        //蓝牙模式	
			OLED_P6x8Str(120,7,"2",1);
			key_set2=1;
			key_set1=0;
			Get_Maopi();		      //初始化去皮
			break;
		}
		if(key_set1==1)     //实时显示重量模式
		{
//			 
//**********************读取重量***********************			
			delay_ms( 10 );
			if ( t++ > 10 )
			{
				t = 0;
				/* 刷新重量的显示 */
				Get_Weight();
				if ( Flag_Error == 0 )
				{
					shiwu = Weight_Shiwu -fuwei ; /* 单位是g */	    						
				}else
				{
					shiwu=0;//读取异常 ，一般不会异常
				}

//*************************显示**************************
				Oled_Printf_U16(50,0,(int)shiwu,1);
				OLED_P8x16Str(100,0,"g",1);
				OLED_P8x16Str(3,0,"weight",1);
				printf("净重量 = %d g\r\n",(int)shiwu); //打印 			
			}
		}
		if(key_set2==1)     //蓝牙模式	
		{
			OLED_P8x16Str(3,0,"blue  ",1);
			delay_ms( 10 );
			if ( t++ > 10 )
			{
				t = 0;
				/* 刷新重量的显示 */
				Get_Weight();
				if ( Flag_Error == 0 )
				{
					shiwu = Weight_Shiwu -fuwei ; /* 单位是g */	    						
				}else
				{
					shiwu=0;//读取异常 ，一般不会异常
				}

//*************************显示**************************
				Oled_Printf_U16(50,0,(int)shiwu,1);
				OLED_P8x16Str(100,0,"g",1);
				printf("净重量 = %d g\r\n",(int)shiwu); //打印 			
			}
      if(key_set0==1)        //发送
			{
				u3_printf("%d\r\n",shiwu);    //显示重量
				u3_printf("%s\r\n","g");      //发送符号
				key_set0=0;
		  }
		}			
	}
}
