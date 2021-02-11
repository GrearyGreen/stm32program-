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
 ALIENTEKս��STM32������ʵ��32
 MPU6050���ᴫ���� ʵ��
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


//����1����1���ַ� 
//c:Ҫ���͵��ַ�
	extern u8  TIM5CH1_CAPTURE_STA;		//���벶��״̬		    				
extern u16	TIM5CH1_CAPTURE_VAL;	//���벶��ֵ
void usart1_send_char(u8 c)
{   	
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); //ѭ������,ֱ���������   
	USART_SendData(USART1,c);  
} 
//�������ݸ�����������λ�����(V2.6�汾)
//fun:������. 0XA0~0XAF
//data:���ݻ�����,���28�ֽ�!!
//len:data����Ч���ݸ���
void usart1_niming_report(u8 fun,u8*data,u8 len)
{
	u8 send_buf[32];
	u8 i;
	if(len>28)return;	//���28�ֽ����� 
	send_buf[len+3]=0;	//У��������
	send_buf[0]=0X88;	//֡ͷ
	send_buf[1]=fun;	//������
	send_buf[2]=len;	//���ݳ���
	for(i=0;i<len;i++)send_buf[3+i]=data[i];			//��������
	for(i=0;i<len+3;i++)send_buf[len+3]+=send_buf[i];	//����У���	
	for(i=0;i<len+4;i++)usart1_send_char(send_buf[i]);	//�������ݵ�����1 
}
//���ͼ��ٶȴ��������ݺ�����������
//aacx,aacy,aacz:x,y,z������������ļ��ٶ�ֵ
//gyrox,gyroy,gyroz:x,y,z�������������������ֵ
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
	usart1_niming_report(0XA1,tbuf,12);//�Զ���֡,0XA1
}	
//ͨ������1�ϱ���������̬���ݸ�����
//aacx,aacy,aacz:x,y,z������������ļ��ٶ�ֵ
//gyrox,gyroy,gyroz:x,y,z�������������������ֵ
//roll:�����.��λ0.01�ȡ� -18000 -> 18000 ��Ӧ -180.00  ->  180.00��
//pitch:������.��λ 0.01�ȡ�-9000 - 9000 ��Ӧ -90.00 -> 90.00 ��
//yaw:�����.��λΪ0.1�� 0 -> 3600  ��Ӧ 0 -> 360.0��
void usart1_report_imu(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz,short roll,short pitch,short yaw)
{
	u8 tbuf[28]; 
	u8 i;
	for(i=0;i<28;i++)tbuf[i]=0;//��0
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
	usart1_niming_report(0XAF,tbuf,28);//�ɿ���ʾ֡,0XAF
}  
 	
 int main(void)
 {	 
	 u32 temper=0;
	float distance;
	unsigned char i;
	 
	u8 t=0,report=1;			//Ĭ�Ͽ����ϱ�
	u8 key;
	float pitch,roll,yaw; 		//ŷ����
	short aacx,aacy,aacz;		//���ٶȴ�����ԭʼ����
	short gyrox,gyroy,gyroz;	//������ԭʼ����
	float temp;					//�¶�	
	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��500000
	delay_init();	//��ʱ��ʼ�� 
	usmart_dev.init(72);		//��ʼ��USMART
	LED_Init();		  			//��ʼ����LED���ӵ�Ӳ���ӿ�
	KEY_Init();					//��ʼ������
	OLED_Init();	 
	MPU_Init();					//��ʼ��MPU6050
		Cbs_Init();   //������ģ���ʼ��
	 TIM5_Cap_Init(0XFFFF,72-1);	//��1Mhz��Ƶ�ʼ���
//	 	 OLED_CLS();//����
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
	
//	  OLED_CLS();//����
 	while(1)
	{ 
		unsigned char dis[10];
		key=KEY_Scan(0);
		if(key==KEY0_PRES)
		{
			report=!report;//�Ƿ�������
		}
//		 delay_ms(1000); //��ʱ
		 
			Start_Measure();    //��ʼ��� 
			if(TIM5CH1_CAPTURE_STA&0X80)//�ɹ�������һ��������
		{
			temper=TIM5CH1_CAPTURE_STA&0X3F;
			temper*=65536;//���ʱ���ܺ�
			temper+=TIM5CH1_CAPTURE_VAL;//�õ��ܵĸߵ�ƽʱ��
			printf("HIGH:%d us    ",temper);//��ӡ�ܵĸߵ�ƽʱ��
			TIM5CH1_CAPTURE_STA=0;//������һ�β���
			distance = (float)temper/1000000*340/2;
			printf("DISTANCE:%f m\r\n",distance);//��ӡ����
		
			OLED_P6x8Str(66,3,dis,1);
			sprintf((char *)dis,"%0.6f",distance);
		 
     printf("����Ϊ%f\n\r",distance);
		
		}
		
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		{   
		
			temp=(float)MPU_Get_Temperature();	//�õ��¶�ֵ
			MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
			if(report)mpu6050_send_data(aacx,aacy,aacz,gyrox,gyroy,gyroz);//���Զ���֡���ͼ��ٶȺ�������ԭʼ����
			if(report)usart1_report_imu(aacx,aacy,aacz,gyrox,gyroy,gyroz,(int)(roll*100),(int)(pitch*100),(int)(yaw*10));
			if((t%10)==0)
			{ 
        temp/=100;
				Oled_Printf_Float(18,1,temp,0);
							
	/**********��ʾ�¶�******/			
							
				temp=(float)pitch;
				Oled_Printf_Float(18,3,temp,0);
				
	/**********��ʾ�Ƕ�1******/				
					
				temp=(float)roll;
				Oled_Printf_Float(18,5,temp,0);
				
	/**********��ʾ�Ƕ�2******/				
				
				temp=(float)yaw;
				Oled_Printf_Float(18,7,temp,0); 
	
 /**********��ʾ�Ƕ�3******/	

				
				//				temp=distance;
//				Oled_Printf_Float(72,1,temp,0);
 /***********��ʾ����*******/				
				t=0;
				LED0=!LED0;//LED��˸
			}
		}
	
		t++; 
	} 	
}
 


