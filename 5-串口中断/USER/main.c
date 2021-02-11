#include "stm32f10x.h"


/************************************************
 ALIENTEK ս��STM32F103������ʵ��0
 ����ģ��
 ע�⣬�����ֲ��е��½������½�ʹ�õ�main�ļ� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


void My_USART1_Init(void)
{
	//�ṹ��
	GPIO_InitTypeDef GPIO_InitStrue;					//�ܽ�ʱ��ʹ��
	USART_InitTypeDef USART_InitStrue;					//����ʹ��
	NVIC_InitTypeDef NVIC_InitStrue;					//�ж�ʹ��
	
	//ʱ��ʹ��
	//ͨ�Źܽ�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//��
	//����ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	//�ܽų�ʼ��
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_AF_PP;			//ʹ������ʽ���ù���
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrue);//��
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_IN_FLOATING;		//ʹ�����븡��
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrue);//��
	
	//���ڽṹ���ʼ��
	USART_InitStrue.USART_BaudRate=115200;				//������
	USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStrue.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;//��������
	USART_InitStrue.USART_Parity=USART_Parity_No;		//�Ƿ�����żУ��
	USART_InitStrue.USART_StopBits=USART_StopBits_1;	//������־λ
	USART_InitStrue.USART_WordLength=USART_WordLength_8b;//����λ��
	
	//���ڳ�ʼ��
	USART_Init(USART1,&USART_InitStrue);//��
	
	//����һ����ʹ��
	USART_Cmd(USART1,ENABLE);//ʹ�ܴ���1
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//���������ж�
	
	//�ж�����
	NVIC_InitStrue.NVIC_IRQChannel=USART1_IRQn;	//�ж�ͨ��
	NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE;	//ͨ��ʹ��
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=1;		//��ռ���ȼ�
	NVIC_InitStrue.NVIC_IRQChannelSubPriority=1;			//��Ӧ���ȼ�
	NVIC_Init(&NVIC_InitStrue);					//�ж����ó�ʼ��
	
	
}

void USART1_IRQHandler(void)		//�����жϷ���
{
	u8 res;
	if(USART_GetITStatus(USART1,USART_IT_RXNE))		//���ʽ������ݱ�־λ
	{
		res= USART_ReceiveData(USART1); 			//��ȡ��������
		USART_SendData(USART1,res);   				//���ͽ�������
	}
}
 
 int main(void)
 {	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		//�Է������Ͷ�����
	My_USART1_Init();		//���ڳ�ʼ��
	while(1);
	 
 }
