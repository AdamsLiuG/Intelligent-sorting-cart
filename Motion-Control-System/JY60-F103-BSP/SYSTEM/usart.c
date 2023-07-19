#include "stm32f10x.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "delay.h"


#define RXBUFFERSIZE  255     //最大接收字节数
char RxBuffer[RXBUFFERSIZE];   //接收数据

uint8_t aRxBuffer;			//接收中断缓冲
uint8_t Uart1_Rx_Cnt = 0;		//接收缓冲计数
uint8_t RxSucceeflag = 0;				//	接收成功标记位
float aX = 0;			//	X轴上的加速度
float aY = 0;			//	Y轴上的加速度
float aZ = 0;			//	Z轴上的加速度

float wX = 0;			//	X轴上的角速度
float wY = 0;			//	Y轴上的角速度
float wZ = 0;			//	Z轴上的角速度

float RollX = 0;	//	滚转角
float PitchY = 0;	//	俯仰角
float YawZ	= 0;	//	偏航角




void uart1_init(u32 bound){
  //GPIO端口设置
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//使能USART1，GPIOA时钟
  
	//USART1_TX   GPIOA.9
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.9
   
  //USART1_RX	  GPIOA.10初始化
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.10  
 
  //Usart1 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
  
   //USART 初始化设置
 
	USART_InitStructure.USART_BaudRate = bound;//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
 
  USART_Init(USART1, &USART_InitStructure); //初始化串口1
  USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);//开启串口接受中断  串口1暂时不需要接收数据，只需要发送数据即可
  USART_Cmd(USART1, ENABLE);                    //使能串口1 
}

void uart3_init(u32 bound){
  //GPIO端口设置
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//使能GPIOA时钟 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);	//使能USART3时钟 
  
	//USART1_TX   GPIOA.2
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //PA.2
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOA.2
   
  //USART1_RX	  GPIOA.3初始化
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;//PA3
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOA.3  
 
  //Usart1 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
  
   //USART 初始化设置
 
	USART_InitStructure.USART_BaudRate = bound;//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
 
  USART_Init(USART3, &USART_InitStructure); //初始化串口1
  USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//开启串口接受中断
  USART_Cmd(USART3, ENABLE);                    //使能串口1 
}

int checkSum(char RxBuf[])
{
	int i;				//	循环变量
	int sum = 0;
	for(i=0;i<10;i++)
	{
		sum = sum+RxBuf[i];
	}
	if(RxBuf[10] == (char)(sum))
	{
		return 1;				//	返回1表示数据正确
	}
	else
	{
		return -1;				//	返回-1表示数据不正确
	}
}


void USART3_IRQHandler(void)                	//串口2中断服务程序
{
	char tempBuffer[100] = "";   // 中间转存数组
	char i = 0; 								 //	循环变量	
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);//清除标志位
		aRxBuffer =USART_ReceiveData(USART3);//(USART1->DR);	//读取接收到的数据
		RxBuffer[Uart1_Rx_Cnt++] = aRxBuffer;			//	接收数据
		
		if(2 == Uart1_Rx_Cnt && (0X55 != RxBuffer[0] || 0X51 != RxBuffer[1]))
		{
			memset(RxBuffer,0x00,sizeof(RxBuffer)); //清空数组
			Uart1_Rx_Cnt = 0;		//	置0
			USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//开启串口接受中断  为了处理数据
			return;
		}
		
		if(44 == Uart1_Rx_Cnt)
		{
			RxSucceeflag = 1;					//	数据成功接收标志
			USART_ITConfig(USART3, USART_IT_RXNE, DISABLE);//关闭串口接受中断  为了处理数据
			
			if(0X51 == RxBuffer[1])
			{
				memset(tempBuffer,0x00,sizeof(tempBuffer)); //清空数组
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
				memset(tempBuffer,0x00,sizeof(tempBuffer)); //清空数组
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
				memset(tempBuffer,0x00,sizeof(tempBuffer)); //清空数组
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
			memset(RxBuffer,0x00,sizeof(RxBuffer)); //清空数组
			Uart1_Rx_Cnt = 0;		//	置0
					
			USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//开启串口接受中断  为了处理数据
		}		 
	}
}



