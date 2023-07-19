/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-07-08     Adams Liu    first version
 */

#include "ToArtpi_uart.h"
#include "stdio.h"
#define THREAD_PRIORITY         2
#define THREAD_STACK_SIZE       1024
#define THREAD_TIMESLICE        5

extern int sign;
extern int _x1;
extern int _y1;
extern int _x2;
extern int _y2;
extern int x_mid;
int class_sign;

float temperature;
float humidity;
float light;
float bit_Point;
float bit_read;

#define SAMPLE_UART5_NAME    "uart5"
static rt_device_t serial5;
struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;

char str[40] ={};
char str_temp[40] ={};
int i;

void uart_initial(void)
{
    /* ����ϵͳ�еĴ����豸 */
    serial5 = rt_device_find(SAMPLE_UART5_NAME);
    if (!serial5)
    {
        rt_kprintf("find %s failed!\n", SAMPLE_UART5_NAME);
        return RT_ERROR;
    }
    else
    {
        rt_kprintf("successful!");
    }
    /* step2���޸Ĵ������ò��� */
    config.baud_rate = BAUD_RATE_115200;        //�޸Ĳ�����Ϊ 115200
    config.data_bits = DATA_BITS_8;           //����λ 8
    config.stop_bits = STOP_BITS_1;           //ֹͣλ 1
    config.bufsz     = 512;                   //�޸Ļ����� buff size Ϊ 128
    config.parity    = PARITY_NONE;           //����żУ��λ

    /* step3�����ƴ����豸��ͨ�����ƽӿڴ�����������֣�����Ʋ��� */
    rt_device_control(serial5, RT_DEVICE_CTRL_CONFIG, &config);

}

void uart_send(void)
{
        /* step4���򿪴����豸�����жϽ��ռ���ѯ����ģʽ�򿪴����豸 */
        rt_device_open(serial5, RT_DEVICE_FLAG_INT_RX);//RT_DEVICE_FLAG_INT_RX 0x100 �жϽ���
//        rt_thread_mdelay(800);
        /* �����ַ��� */
//        x_mid = (_x1+_x2)*0.5;
//        rt_kprintf(x_mid);
        class_sign = sign;
        sprintf(str_temp, "#%d*%d&\n", x_mid, class_sign);
        rt_device_write(serial5, 0, str_temp, (sizeof(str_temp) - 1));
        rt_kprintf(str_temp);
        rt_device_close(serial5);//�ر��豸
}

////#include <drv_common.h>
////#include <string.h>
////#include <stdio.h>
////#include "ToF407_uart.h"
////#include <stdlib.h>
////#define SAMPLE_UART5_NAME       "uart5"
//struct rt_semaphore      rx_sem5;
////static rt_device_t          serial5;
//
////char str_recv[40] ={};
////char str_temp_recv[40] ={};
//
//static rt_err_t uart5_rx_ind(rt_device_t dev, rt_size_t size)
//{
//    if (size > 0)
//    {
//        rt_sem_release(&rx_sem5);
//    }
//    return RT_EOK;
//}
//
//static rt_err_t uart_get_char(void)
//{
//    char ch;
//    static uint8_t recv_flag = 1;
//
//    while (rt_device_read(serial5, 0, &ch, 1) == 0)
//    {
//        rt_sem_control(&rx_sem5, RT_IPC_CMD_RESET, RT_NULL);
//        if(recv_flag)
//        {
//            rt_sem_take(&rx_sem5, RT_WAITING_FOREVER);
//        }
//        else if(-RT_ETIMEOUT == rt_sem_take(&rx_sem5, 100))//��ʱ100msδ��ô�������  100�Ǹ���ʱ�ӽ������� ���ĵ�λ��1/RT_TICK_PER_SECOND ��
//        {
//            recv_flag = 1; //����һ֡
//            ch = '\n'; //Ҳ�����ñ�ĵ�α֡β
//            return ch;
//        }
//    }
//    recv_flag = 0; //������ȡһ���ֽ�
//    return ch;
//}
//
//// ���ݽ����߳�
//static void data_parse(void)
//{
//    char rx_temp = 0;
//    char rx_len = 0;
//    char data_buf[30] = {0};
//
//    while(1)
//    {
//        rx_temp = uart_get_char();
//        if(rx_temp != '\n')
//        {
//            data_buf[(rx_len++)%30] = rx_temp;
//        }
//        else
//        {
//            rx_len = 0;
//            rt_kprintf("uart5 received data is %s\r\n",data_buf);
//            if(data_buf[0]=='#')
//            {
//                i = 1;
//                temperature = 0;
//                humidity = 0;
//                light = 0;
//                while(data_buf[i]!= '*' && i<20)
//                {
//
//                    if(data_buf[i]!='.')
//                    {
//                        temperature = 10 * temperature;
//                        bit_read = data_buf[i] - '0';
//                        temperature += bit_read;
//                    }
//                    else if(data_buf[i] == '.')
//                    {
//                        i++;
//                        bit_Point = (float)(data_buf[i] - '0')/10;
//                        temperature = temperature + bit_Point;
//                    }
//                    i++;
//                }
//                i++;
//                while(data_buf[i]!= '!' && i<20)
//                 {
//                    if(data_buf[i]!='.')
//                    {
//                        humidity = 10 * humidity;
//                        bit_read = data_buf[i] - '0';
//                        humidity += bit_read;
//                    }
//                    else if(data_buf[i] == '.')
//                    {
//                        i++;
//                        bit_Point = (float)(data_buf[i] - '0')/10;
//                        humidity = humidity + bit_Point;
//                    }
//                    i++;
//                  }
//                i++;
//                while(data_buf[i]!= '&' && i<20)
//                 {
//                    if(data_buf[i]!='.')
//                    {
//                        light = 10 * light;
//                        bit_read = data_buf[i] - '0';
//                        light += bit_read;
//                    }
//                    else if(data_buf[i] == '.')
//                    {
//                        i++;
//                        bit_Point = (float)(data_buf[i] - '0')/10;
//                        light = light + bit_Point;
//                    }
//                    i++;
//                  }
//                sprintf(str, "humi%.1f\r\n",light);
//                rt_kprintf(str);
//            }
//            memset(data_buf, 0, sizeof(data_buf));
//        }
//    }
//}
//
//int uart5_function(void)
//{
//    rt_err_t ret = RT_EOK;
////    char str[] = "hello RT-Thread!\r\n";
//    serial5 = rt_device_find(SAMPLE_UART5_NAME);
//    if(!serial5)
//    {
//        rt_kprintf("find %s failed!\n",SAMPLE_UART5_NAME);
//        return RT_ERROR;
//    }
//
//
////    rt_kprintf("-----------------");
//    /* ��ʼ���ź��� */
//    rt_sem_init(&rx_sem5, "rx_sem5", 0, RT_IPC_FLAG_FIFO);
//    /* ���жϽ��ռ���ѯ����ģʽ�򿪴����豸 */
//    rt_device_open(serial5,RT_DEVICE_FLAG_INT_RX);
//    /* ���ý��ջص����� */
//    rt_device_set_rx_indicate(serial5, uart5_rx_ind);
//    /* ���� serial �߳� */
//    rt_thread_t thread = rt_thread_create("thread_uart5", (void (*)(void *parameter))data_parse,
//                                           RT_NULL, 1024, 24, 10);
//    /* �����ɹ��������߳� */
//    if (thread != RT_NULL)
//    {
//        rt_thread_startup(thread);
//    }
//    else
//    {
//        ret = RT_ERROR;
//    }
//
//    return ret;
//}
//
//INIT_APP_EXPORT(uart5_function);
//////MSH_CMD_EXPORT(uart5_function, uart5 function sample);
