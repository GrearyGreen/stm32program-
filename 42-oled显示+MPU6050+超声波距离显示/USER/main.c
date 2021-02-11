#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "mpu6050.h"
#include "usmart.h"   
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include "oled.h"
 #include "cbs.h"
/************************************************
 ALIENTEK战舰STM32开发板实验32
 MPU6050六轴传感器 实验
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/


//串口1发送1个字符 
//c:要发送的字符
	extern u8  TIM5CH1_CAPTURE_STA;		//输入捕获状态		    				
extern u16	TIM5CH1_CAPTURE_VAL;	//输入捕获值
void usart1_send_char(u8 c)
{   	
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); //循环发送,直到发送完毕   
	USART_SendData(USART1,c);  
} 
//传送数据给匿名四轴上位机软件(V2.6版本)
//fun:功能字. 0XA0~0XAF
//data:数据缓存区,最多28字节!!
//len:data区有效数据个数
void usart1_niming_report(u8 fun,u8*data,u8 len)
{
	u8 send_buf[32];
	u8 i;
	if(len>28)return;	//最多28字节数据 
	send_buf[len+3]=0;	//校验数置零
	send_buf[0]=0X88;	//帧头
	send_buf[1]=fun;	//功能字
	send_buf[2]=len;	//数据长度
	for(i=0;i<len;i++)send_buf[3+i]=data[i];			//复制数据
	for(i=0;i<len+3;i++)send_buf[len+3]+=send_buf[i];	//计算校验和	
	for(i=0;i<len+4;i++)usart1_send_char(send_buf[i]);	//发送数据到串口1 
}
//发送加速度传感器数据和陀螺仪数据
//aacx,aacy,aacz:x,y,z三个方向上面的加速度值
//gyrox,gyroy,gyroz:x,y,z三个方向上面的陀螺仪值
void mpu6050_send_data(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz)
{
	u8 tbuf[12]; 
	tbuf[0]=(aacx>>8)&0XFF;
	tbuf[1]=aacx&0XFF;
	tbuf[2]=(aacy>>8)&0XFF;
	tbuf[3]=aacy&0XFF;
	tbuf[4]=(aacz>>8)&0XFF;
	tbuf[5]=aacz&0XFF; 
	tbuf[6]=(gyrox>>8)&0XFF;
	tbuf[7]=gyrox&0XFF;
	tbuf[8]=(gyroy>>8)&0XFF;
	tbuf[9]=gyroy&0XFF;
	tbuf[10]=(gyroz>>8)&0XFF;
	tbuf[11]=gyroz&0XFF;
	usart1_niming_report(0XA1,tbuf,12);//自定义帧,0XA1
}	
//通过串口1上报结算后的姿态数据给电脑
//aacx,aacy,aacz:x,y,z三个方向上面的加速度值
//gyrox,gyroy,gyroz:x,y,z三个方向上面的陀螺仪值
//roll:横滚角.单位0.01度。 -18000 -> 18000 对应 -180.00  ->  180.00度
//pitch:俯仰角.单位 0.01度。-9000 - 9000 对应 -90.00 -> 90.00 度
//yaw:航向角.单位为0.1度 0 -> 3600  对应 0 -> 360.0度
void usart1_report_imu(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz,short roll,short pitch,short yaw)
{
	u8 tbuf[28]; 
	u8 i;
	for(i=0;i<28;i++)tbuf[i]=0;//清0
	tbuf[0]=(aacx>>8)&0XFF;
	tbuf[1]=aacx&0XFF;
	tbuf[2]=(aacy>>8)&0XFF;
	tbuf[3]=aacy&0XFF;
	tbuf[4]=(aacz>>8)&0XFF;
	tbuf[5]=aacz&0XFF; 
	tbuf[6]=(gyrox>>8)&0XFF;
	tbuf[7]=gyrox&0XFF;
	tbuf[8]=(gyroy>>8)&0XFF;
	tbuf[9]=gyroy&0XFF;
	tbuf[10]=(gyroz>>8)&0XFF;
	tbuf[11]=gyroz&0XFF;	
	tbuf[18]=(roll>>8)&0XFF;
	tbuf[19]=roll&0XFF;
	tbuf[20]=(pitch>>8)&0XFF;
	tbuf[21]=pitch&0XFF;
	tbuf[22]=(yaw>>8)&0XFF;
	tbuf[23]=yaw&0XFF;
	usart1_niming_report(0XAF,tbuf,28);//飞控显示帧,0XAF
}  
 	
 int main(void)
 {	 
	 u32 temper=0;
	float distance;
	unsigned char i;
	 
	u8 t=0,report=1;			//默认开启上报
	u8 key;
	float pitch,roll,yaw; 		//欧拉角
	short aacx,aacy,aacz;		//加速度传感器原始数据
	short gyrox,gyroy,gyroz;	//陀螺仪原始数据
	float temp;					//温度	
	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化500000
	delay_init();	//延时初始化 
	usmart_dev.init(72);		//初始化USMART
	LED_Init();		  			//初始化与LED连接的硬件接口
	KEY_Init();					//初始化按键
	OLED_Init();	 
	MPU_Init();					//初始化MPU6050
		Cbs_Init();   //超声波模块初始化
	 TIM5_Cap_Init(0XFFFF,72-1);	//以1Mhz的频率计数
//	 	 OLED_CLS();//清屏
	while(mpu_dmp_init())
 	{
		OLED_P6x8Str(8,1,"Error",0);
		delay_ms(200);
		OLED_CLS();
 		delay_ms(200);
	}  
	
	DrawLine(60,0,60,77,1);
	OLED_P6x8Str(6,1,"T:     C",0);
	OLED_P6x8Str(6,3,"P:     C",0);
	OLED_P6x8Str(6,5,"R:     C",0);
	OLED_P6x8Str(6,7,"Y:     C",0);
	OLED_P6x8Str(66,1,"d:   ",0);
	
//	  OLED_CLS();//清屏
 	while(1)
	{ 
		unsigned char dis[10];
		key=KEY_Scan(0);
		if(key==KEY0_PRES)
		{
			report=!report;//是否发送数据
		}
//		 delay_ms(1000); //延时
		 
			Start_Measure();    //开始测距 
			if(TIM5CH1_CAPTURE_STA&0X80)//成功捕获到了一次上升沿
		{
			temper=TIM5CH1_CAPTURE_STA&0X3F;
			temper*=65536;//溢出时间总和
			temper+=TIM5CH1_CAPTURE_VAL;//得到总的高电平时间
			printf("HIGH:%d us    ",temper);//打印总的高点平时间
			TIM5CH1_CAPTURE_STA=0;//开启下一次捕获
			distance = (float)temper/1000000*340/2;
			printf("DISTANCE:%f m\r\n",distance);//打印距离
		
			OLED_P6x8Str(66,3,dis,1);
			sprintf((char *)dis,"%0.6f",distance);
		 
     printf("距离为%f\n\r",distance);
		
		}
		
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		{   
		
			temp=(float)MPU_Get_Temperature();	//得到温度值
			MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
			if(report)mpu6050_send_data(aacx,aacy,aacz,gyrox,gyroy,gyroz);//用自定义帧发送加速度和陀螺仪原始数据
			if(report)usart1_report_imu(aacx,aacy,aacz,gyrox,gyroy,gyroz,(int)(roll*100),(int)(pitch*100),(int)(yaw*10));
			if((t%10)==0)
			{ 
        temp/=100;
				Oled_Printf_Float(18,1,temp,0);
							
	/**********显示温度******/			
							
				temp=(float)pitch;
				Oled_Printf_Float(18,3,temp,0);
				
	/**********显示角度1******/				
					
				temp=(float)roll;
				Oled_Printf_Float(18,5,temp,0);
				
	/**********显示角度2******/				
				
				temp=(float)yaw;
				Oled_Printf_Float(18,7,temp,0); 
	
 /**********显示角度3******/	

				
				//				temp=distance;
//				Oled_Printf_Float(72,1,temp,0);
 /***********显示距离*******/				
				t=0;
				LED0=!LED0;//LED闪烁
			}
		}
	
		t++; 
	} 	
}
 


