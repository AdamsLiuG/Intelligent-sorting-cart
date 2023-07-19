#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>

#define TXBUFFERSIZE  255     //�������ֽ���
char TxBuffer[TXBUFFERSIZE];   //��������


/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	int i = 0;
	delay_init();						//	��ʱ������ʼ��
	uart1_init(115200);				//	����1������ʼ��
	uart3_init(9600);				//	����1������ʼ��

  /* Infinite loop 	*/
  while (1)
  {
		if(1 == RxSucceeflag)
		{
			RxSucceeflag = 0;
			memset(TxBuffer,0x00,sizeof(TxBuffer)); //�������
			sprintf(TxBuffer,"#%.1f&\n",YawZ); //��������
			for(i=0;i<strlen(TxBuffer);i++)
			{
				USART_SendData(USART1, TxBuffer[i]);//����
				delay_ms(1);
			}
			
		}
  }
}


