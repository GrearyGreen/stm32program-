#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "stm32f10x.h"
#include "OLED_I2C.h"
#include "ds18b20.h"
#include "cbs.h"


 
/************************************************
 ALIENTEK战舰STM32开发板实验1
 跑马灯实验 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
	extern u8  TIM5CH1_CAPTURE_STA;		//输入捕获状态		    				
extern u16	TIM5CH1_CAPTURE_VAL;	//输入捕获值
	
	int main (void)
{	 
	u32 temper=0;
	float distance;
	unsigned char i;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //时钟设置
  uart_init(115200);//串口初始化（参数是波特率）
	delay_init();
	//主程序
 
		Cbs_Init();   //超声波模块初始化
	TIM5_Cap_Init(0XFFFF,72-1);	//以1Mhz的频率计数
	DS18B20_Init();	//温度模块初始化
	
	LED_Init();//led初始化
	
	I2C_Configuration();  //初始化olediic

  OLED_Init();       //初始化oled模块,一定要接上去后面才会工作
	
	//主循环
	 OLED_CLS();//清屏
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
//	 //   OLED_CLS();//清屏
//			for(i=0;i<2;i++)
//		 {
//			OLED_ShowCN(i*16,0,i);//显示数据中文
//	   }
//		

//		 sprintf((char *)temp,"%0.6f",tem);
//		 OLED_ShowStr(0,3,temp,1);
//     printf("DS18B20读取温度值为%f\n\r",tem);
//			

//      delay_ms(1000); //延时
//		 	OLED_Fill(0xFF);//全屏点亮
//		 delay_ms(1000); //延时
//		OLED_Fill(0x00);//全屏灭
		 delay_ms(1000); //延时
		 Start_Measure();    //开始测距

			 
			for(i=0;i<2;i++)
		 {
			OLED_ShowCN(i*16,0,i);//显示数据中文
	   }
		 	if(TIM5CH1_CAPTURE_STA&0X80)//成功捕获到了一次上升沿
		{
			temper=TIM5CH1_CAPTURE_STA&0X3F;
			temper*=65536;//溢出时间总和
			temper+=TIM5CH1_CAPTURE_VAL;//得到总的高电平时间
			printf("HIGH:%d us    ",temper);//打印总的高点平时间
			TIM5CH1_CAPTURE_STA=0;//开启下一次捕获
			distance = (float)temper/1000000*340/2;
			printf("DISTANCE:%f m\r\n",distance);//打印距离
		
			
			sprintf((char *)dis,"%0.6f",distance);
		 OLED_ShowStr(0,3,dis,1);
     printf("距离为%f\n\r",distance);
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
//	I2C_Configuration();  //初始化olediic
//	OLED_Init();       //初始化oled模块
//	LED_Init();		  	//初始化与LED连接的硬件接口



//	while(1)
//	{

//		for(i=0;i<2;i++)
//		{
//			OLED_ShowCN(i*16,0,i);//测试显示中文
//		}
//		delay_ms(20000);
//		
//		for(i=0;i<5;i++)
//		{
//		
//		OLED_ShowStr(0,3,"",1);//测试6*8字符
//		}
//		
//		OLED_ShowStr(0,4,"Hello Tech",2);				//测试8*16字符
//		delay_ms(20000);
//		OLED_CLS();//清屏
//		OLED_OFF();//测试OLED休眠
//		delay_ms(20000);
//		OLED_ON();//测试OLED休眠后唤醒
//	
//	} 
// }
//	delay_init();	    //延时函数初始化	  
//	LED_Init();		  	//初始化与LED连接的硬件接口
//	while(1)
//	{
//		LED0=0;
//		LED1=1;
//		delay_ms(300);	 //延时300ms
//		LED0=1;
//		LED1=0;
//		delay_ms(300);	//延时300ms
//	}



 /**
 *****************下面注视的代码是通过调用库函数来实现IO控制的方法*****************************************

 unsigned char i;
	extern const unsigned char BMP1[];
	
	delay_init();
	I2C_Configuration();
	OLED_Init();
	
	while(1)
	{
		OLED_Fill(0xFF);//全屏点亮
		OLED_Fill(0x00);//全屏灭
		for(i=0;i<5;i++)
		{
			OLED_ShowCN(22+i*16,0,i);//测试显示中文
		}
		delay_ms(20000);
		OLED_ShowStr(0,3,"HelTec Automation",1);//测试6*8字符
		OLED_ShowStr(0,4,"Hello Tech",2);				//测试8*16字符
		delay_ms(20000);
		OLED_CLS();//清屏
		OLED_OFF();//测试OLED休眠
		delay_ms(20000);
		OLED_ON();//测试OLED休眠后唤醒
		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//测试BMP位图显示
		delay_ms(20000);
	}
 ****************************************************************************************************
 ***/
 


