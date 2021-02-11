#include "stm32f10x.h"


/************************************************
 ALIENTEK 战舰STM32F103开发板实验0
 工程模板
 注意，这是手册中的新建工程章节使用的main文件 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/


void My_USART1_Init(void)
{
	//结构体
	GPIO_InitTypeDef GPIO_InitStrue;					//管脚时钟使能
	USART_InitTypeDef USART_InitStrue;					//串口使能
	NVIC_InitTypeDef NVIC_InitStrue;					//中断使能
	
	//时钟使能
	//通信管脚时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//①
	//串口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	//管脚初始化
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_AF_PP;			//使用推挽式复用功能
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrue);//②
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_IN_FLOATING;		//使用输入浮空
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrue);//②
	
	//串口结构体初始化
	USART_InitStrue.USART_BaudRate=115200;				//波特率
	USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStrue.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;//输入和输出
	USART_InitStrue.USART_Parity=USART_Parity_No;		//是否有奇偶校验
	USART_InitStrue.USART_StopBits=USART_StopBits_1;	//结束标志位
	USART_InitStrue.USART_WordLength=USART_WordLength_8b;//数据位数
	
	//串口初始化
	USART_Init(USART1,&USART_InitStrue);//③
	
	//串口一控制使能
	USART_Cmd(USART1,ENABLE);//使能串口1
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//开启接收中断
	
	//中断配置
	NVIC_InitStrue.NVIC_IRQChannel=USART1_IRQn;	//中断通道
	NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE;	//通道使能
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=1;		//抢占优先级
	NVIC_InitStrue.NVIC_IRQChannelSubPriority=1;			//响应优先级
	NVIC_Init(&NVIC_InitStrue);					//中断配置初始化
	
	
}

void USART1_IRQHandler(void)		//串口中断服务
{
	u8 res;
	if(USART_GetITStatus(USART1,USART_IT_RXNE))		//访问接受数据标志位
	{
		res= USART_ReceiveData(USART1); 			//获取接收数据
		USART_SendData(USART1,res);   				//发送接收数据
	}
}
 
 int main(void)
 {	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		//以分组类型二工作
	My_USART1_Init();		//串口初始化
	while(1);
	 
 }
