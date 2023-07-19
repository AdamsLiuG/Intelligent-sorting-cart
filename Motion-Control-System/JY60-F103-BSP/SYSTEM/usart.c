#include "stm32f10x.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "delay.h"


#define RXBUFFERSIZE  255     //�������ֽ���
char RxBuffer[RXBUFFERSIZE];   //��������

uint8_t aRxBuffer;			//�����жϻ���
uint8_t Uart1_Rx_Cnt = 0;		//���ջ������
uint8_t RxSucceeflag = 0;				//	���ճɹ����λ
float aX = 0;			//	X���ϵļ��ٶ�
float aY = 0;			//	Y���ϵļ��ٶ�
float aZ = 0;			//	Z���ϵļ��ٶ�

float wX = 0;			//	X���ϵĽ��ٶ�
float wY = 0;			//	Y���ϵĽ��ٶ�
float wZ = 0;			//	Z���ϵĽ��ٶ�

float RollX = 0;	//	��ת��
float PitchY = 0;	//	������
float YawZ	= 0;	//	ƫ����




void uart1_init(u32 bound){
  //GPIO�˿�����
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��USART1��GPIOAʱ��
  
	//USART1_TX   GPIOA.9
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
  GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.9
   
  //USART1_RX	  GPIOA.10��ʼ��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
  GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.10  
 
  //Usart1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
  
   //USART ��ʼ������
 
	USART_InitStructure.USART_BaudRate = bound;//���ڲ�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
 
  USART_Init(USART1, &USART_InitStructure); //��ʼ������1
  USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);//�������ڽ����ж�  ����1��ʱ����Ҫ�������ݣ�ֻ��Ҫ�������ݼ���
  USART_Cmd(USART1, ENABLE);                    //ʹ�ܴ���1 
}

void uart3_init(u32 bound){
  //GPIO�˿�����
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//ʹ��GPIOAʱ�� 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);	//ʹ��USART3ʱ�� 
  
	//USART1_TX   GPIOA.2
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //PA.2
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOA.2
   
  //USART1_RX	  GPIOA.3��ʼ��
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;//PA3
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOA.3  
 
  //Usart1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
  
   //USART ��ʼ������
 
	USART_InitStructure.USART_BaudRate = bound;//���ڲ�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
 
  USART_Init(USART3, &USART_InitStructure); //��ʼ������1
  USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//�������ڽ����ж�
  USART_Cmd(USART3, ENABLE);                    //ʹ�ܴ���1 
}

int checkSum(char RxBuf[])
{
	int i;				//	ѭ������
	int sum = 0;
	for(i=0;i<10;i++)
	{
		sum = sum+RxBuf[i];
	}
	if(RxBuf[10] == (char)(sum))
	{
		return 1;				//	����1��ʾ������ȷ
	}
	else
	{
		return -1;				//	����-1��ʾ���ݲ���ȷ
	}
}


void USART3_IRQHandler(void)                	//����2�жϷ������
{
	char tempBuffer[100] = "";   // �м�ת������
	char i = 0; 								 //	ѭ������	
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)  //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
	{
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);//�����־λ
		aRxBuffer =USART_ReceiveData(USART3);//(USART1->DR);	//��ȡ���յ�������
		RxBuffer[Uart1_Rx_Cnt++] = aRxBuffer;			//	��������
		
		if(2 == Uart1_Rx_Cnt && (0X55 != RxBuffer[0] || 0X51 != RxBuffer[1]))
		{
			memset(RxBuffer,0x00,sizeof(RxBuffer)); //�������
			Uart1_Rx_Cnt = 0;		//	��0
			USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//�������ڽ����ж�  Ϊ�˴�������
			return;
		}
		
		if(44 == Uart1_Rx_Cnt)
		{
			RxSucceeflag = 1;					//	���ݳɹ����ձ�־
			USART_ITConfig(USART3, USART_IT_RXNE, DISABLE);//�رմ��ڽ����ж�  Ϊ�˴�������
			
			if(0X51 == RxBuffer[1])
			{
				memset(tempBuffer,0x00,sizeof(tempBuffer)); //�������
				for(i=0;i<11;i++)
				{
					tempBuffer[i] = RxBuffer[i]; 
				}
				if(1 == checkSum(tempBuffer))
				{
					aX = (float)((float)((RxBuffer[3]<<8)|RxBuffer[2])/32768.0*16*9.8);
					aY = (float)((float)((RxBuffer[5]<<8)|RxBuffer[4])/32768.0*16*9.8);
					aZ = (float)((float)((RxBuffer[7]<<8)|RxBuffer[6])/32768.0*16*9.8);
					
					//USART_SendData(USART1, 'A');
				}
			}
			if(0X52 == RxBuffer[12])
			{
				memset(tempBuffer,0x00,sizeof(tempBuffer)); //�������
				for(i=11;i<22;i++)
				{
					tempBuffer[i-11] = RxBuffer[i]; 
				}
				
				if(1 == checkSum(RxBuffer))
				{
					wX = (float)(((RxBuffer[14]<<8)|RxBuffer[13])/32768.0*2000);
					wY = (float)(((RxBuffer[16]<<8)|RxBuffer[15])/32768.0*2000);
					wZ = (float)(((RxBuffer[18]<<8)|RxBuffer[17])/32768.0*2000);
					
					//USART_SendData(USART1, 'B');
				}
			}
			if(0X53 == RxBuffer[23])
			{
				memset(tempBuffer,0x00,sizeof(tempBuffer)); //�������
				for(i=22;i<33;i++)
				{
					tempBuffer[i-22] = RxBuffer[i]; 
				}
				
				if(1 == checkSum(RxBuffer))
				{
					RollX = (float)(((RxBuffer[25]<<8)|RxBuffer[24])/32768.0*180);
					PitchY = (float)(((RxBuffer[27]<<8)|RxBuffer[26])/32768.0*180);
					YawZ = (float)(((RxBuffer[29]<<8)|RxBuffer[28])/32768.0*180);
					
					//USART_SendData(USART1, 'C'); 
				}
			}
			memset(RxBuffer,0x00,sizeof(RxBuffer)); //�������
			Uart1_Rx_Cnt = 0;		//	��0
					
			USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//�������ڽ����ж�  Ϊ�˴�������
		}		 
	}
}



