#include "usart.h"


//初始化两个UART串口
void tb_usart1_init(u32 rate) 
	{  
  GPIO_InitTypeDef GPIO_InitStructure;  
  USART_InitTypeDef USART_InitStructure; 
	USART_ClockInitTypeDef USART_ClockInitStructure; 	
  NVIC_InitTypeDef NVIC_InitStructure;  
  
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);  
  USART_DeInit(USART1);  
    /* Configure USART Tx as alternate function push-pull */  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_Init(GPIOA, &GPIO_InitStructure);  
      
    /* Configure USART Rx as input floating */  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
	GPIO_Init(GPIOA, &GPIO_InitStructure);  
  
	USART_InitStructure.USART_BaudRate = rate;  
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;  
	USART_InitStructure.USART_StopBits = USART_StopBits_1;  
	USART_InitStructure.USART_Parity = USART_Parity_No;  
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;  
    
	USART_ClockInitStructure.USART_Clock = USART_Clock_Disable;  
	USART_ClockInitStructure.USART_CPOL = USART_CPOL_Low;  
	USART_ClockInitStructure.USART_CPHA = USART_CPHA_2Edge;  
	USART_ClockInitStructure.USART_LastBit = USART_LastBit_Disable;  
	USART_ClockInit(USART1, &USART_ClockInitStructure);  
	USART_Init(USART1, &USART_InitStructure );   
		
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
	NVIC_Init(&NVIC_InitStructure); 
		//开启中断
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//// 使能串口接收中断
    //USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
	
//	USART_ITConfig(USART1, USART_IT_PE, ENABLE);
//	USART_ITConfig(USART1, USART_IT_ERR, ENABLE);

	USART_Cmd(USART1, ENABLE);  
}  
  

void tb_usart3_init(u32 rate) 
	{  
	GPIO_InitTypeDef GPIO_InitStructure;  
  USART_InitTypeDef USART_InitStructure;   
	NVIC_InitTypeDef NVIC_InitStructure; 
	
	
	/* config USART3 clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	
	/* USART3 GPIO config */
	/* Configure USART3 Tx (PB.10) as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);    
	
	/* Configure USART3 Rx (PB.11) as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* USART3 mode config */
	USART_InitStructure.USART_BaudRate = rate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART3, &USART_InitStructure);
		
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);   
	
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
    //USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
	
	//USART_HalfDuplexCmd(USART3,ENABLE);
		
	USART_Cmd(USART3, ENABLE); 
} 

//从串口1发送一个字节

void tb_usart1_send_str(u8 *Data) {
	while(*Data) {
		USART_SendData(USART1, *Data++);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET); 
	}
	return;
}

//从串口3发送一个字节


void tb_usart3_send_str(u8 *Data) {
	while(*Data) {
		USART_SendData(USART3, *Data++);
		while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET); 
	}
	return;
}


/**========================中断处理函数=============================**/
//串口收发中断处理函数
int USART1_IRQHandler(void) {//USART1_IRQHandler() 函数可以是用户自定义的,也可以是STM32标准库提供的默认实现。
	u8 sbuf_bak;
	static u16 buf_index = 0;

	if(USART_GetFlagStatus(USART1,USART_IT_RXNE)==SET) {
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);		
		sbuf_bak = USART_ReceiveData(USART1); 
		//uart1_send_byte(sbuf_bak);
		if(uart3_get_ok)//uart1_get_ok未接受完成时为0
			return 0;
		if(receive_flag == 1)
	  {
		if(sbuf_bak == '<') {
			uart3_mode = 4;
			buf_index = 0;
		}else if(uart3_mode == 0) {
			if(sbuf_bak == '$') {			//命令模式 $XXX!
				uart3_mode = 1;
			} else if(sbuf_bak == '#') {	//单舵机模式	#000P1500T1000! 类似这种命令
				uart3_mode = 2;
			} else if(sbuf_bak == '{') {	//多舵机模式	{#000P1500T1000!#001P1500T1000!} 多个单舵机命令用大括号括起来
				uart3_mode = 3;
			} else if(sbuf_bak == '<') {	//保存动作组模式	<G0000#000P1500T1000!#001P1500T1000!B000!> 用尖括号括起来 带有组序号
				uart3_mode = 4;
			} 
			buf_index = 0;
		}
		
		uart_receive_buf[buf_index++] = sbuf_bak;
				
		if((uart3_mode == 4) && (sbuf_bak == '>')){
			uart_receive_buf[buf_index] = '\0';
			uart3_get_ok = 1;
		} else if((uart3_mode == 1) && (sbuf_bak == '!')){
			uart_receive_buf[buf_index] = '\0';
			uart3_get_ok = 1;//接收完成赋值1
		} else if((uart3_mode == 2) && (sbuf_bak == '!')){
			uart_receive_buf[buf_index] = '\0';
			uart3_get_ok = 1;
		} else if((uart3_mode == 3) && (sbuf_bak == '}')){
			uart_receive_buf[buf_index] = '\0';
			uart3_get_ok = 1;
		}    
	}
		if(buf_index >= UART_BUF_SIZE)buf_index = 0;
	}
	//发送中断 用前在初始化的时候请打开
	//if(USART_GetITStatus(USART1, USART_IT_TXE) != RESET) {   
		//USART_SendData(USARTy, TxBuffer1[TxCounter1++]);
	//}   
	return 0;
}


int USART3_IRQHandler(void) { 
		
	u8 sbuf_bak;
	static u16 buf_index = 0;
	if(USART_GetFlagStatus(USART3,USART_IT_RXNE)==SET) 
	{
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);	
		sbuf_bak = USART_ReceiveData(USART3);
		if(uart3_get_ok)return 0;
		if(receive_flag == 1)
		{
			if(sbuf_bak == '<') 	
			{
				uart3_mode = 4;
				buf_index = 0;
			}
			else if(uart3_mode == 0) {
			if(sbuf_bak == '$') {		
				uart3_mode = 1;
			} else if(sbuf_bak == '#') {
				uart3_mode = 2;
			} else if(sbuf_bak == '{') {
				uart3_mode = 3;
			} else if(sbuf_bak == '<') {
				uart3_mode = 4;
			} 
			buf_index = 0;
		}
		
		uart_receive_buf[buf_index++] = sbuf_bak;
				
		if((uart3_mode == 4) && (sbuf_bak == '>')){
			uart_receive_buf[buf_index] = '\0';
			uart3_get_ok = 1;
		} else if((uart3_mode == 1) && (sbuf_bak == '!')){
			uart_receive_buf[buf_index] = '\0';
			uart3_get_ok = 1;
		} else if((uart3_mode == 2) && (sbuf_bak == '!')){
			uart_receive_buf[buf_index] = '\0';
			uart3_get_ok = 1;
		} else if((uart3_mode == 3) && (sbuf_bak == '}')){
			uart_receive_buf[buf_index] = '\0';
			uart3_get_ok = 1;
		}    
	}
		if(buf_index >= UART_BUF_SIZE)buf_index = 0;
	}
	
	//发送中断 用前在初始化的时候请打开
	//if(USART_GetITStatus(USART3, USART_IT_TXE) != RESET) {   
	//	USART_SendData(USARTy, TxBuffer1[TxCounter1++]);
	//}  
	return 0;
}



void uart1_send_str(u8 *str) {
	tb_usart1_send_str(str);
}





void zx_uart_send_str(u8 *str) {
	uart3_get_ok  = 1;//UART收到数据
	//如果不发送，不能动
	tb_usart3_send_str(str);
	tb_usart1_send_str(str);		
	uart3_get_ok = 0;
}


void uart3_send_str(u8 *str) {
	tb_usart3_send_str(str);	
}



