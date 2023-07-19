#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>

#define TXBUFFERSIZE  255     //最大接收字节数
char TxBuffer[TXBUFFERSIZE];   //接收数据


/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	int i = 0;
	delay_init();						//	延时函数初始化
	uart1_init(115200);				//	串口1函数初始化
	uart3_init(9600);				//	串口1函数初始化

  /* Infinite loop 	*/
  while (1)
  {
		if(1 == RxSucceeflag)
		{
			RxSucceeflag = 0;
			memset(TxBuffer,0x00,sizeof(TxBuffer)); //清空数组
			sprintf(TxBuffer,"#%.1f&\n",YawZ); //复制数组
			for(i=0;i<strlen(TxBuffer);i++)
			{
				USART_SendData(USART1, TxBuffer[i]);//发送
				delay_ms(1);
			}
			
		}
  }
}


