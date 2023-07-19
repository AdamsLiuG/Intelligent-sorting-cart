/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-07-08     Adams Liu    first version
 */

#include <drv_common.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Artpi_Artpi_uart.h>
#define SAMPLE_UART_NAME       "uart1"
struct rt_semaphore      rx_sem1;
static rt_device_t          serial1;

#define THREAD_PRIORITY         2
#define THREAD_STACK_SIZE       1024
#define THREAD_TIMESLICE        5

int i = 0;
char str[30];
int x_mid;
int bit_read;
int bit_num;
int class = 2;

static rt_err_t uart1_rx_ind(rt_device_t dev, rt_size_t size)
{
    /* 串口接收到数据后产生中断，调用此回调函数，然后发送接收信号量 */
    if (size > 0)
    {
        rt_sem_release(&rx_sem1);
    }
    return RT_EOK;
}

static rt_err_t uart_get_char(void)
{
    char ch;
    static uint8_t recv_flag = 1;

    while (rt_device_read(serial1, 0, &ch, 1) == 0)
    {
        rt_sem_control(&rx_sem1, RT_IPC_CMD_RESET, RT_NULL);
        if(recv_flag)
        {
            rt_sem_take(&rx_sem1, RT_WAITING_FOREVER);
        }
        else if(-RT_ETIMEOUT == rt_sem_take(&rx_sem1, 100))//超时100ms未获得串口数据  100是根据时钟节拍来定 节拍单位是1/RT_TICK_PER_SECOND 秒
        {
            recv_flag = 1; //收完一帧
            ch = '\n'; //也可以用别的当伪帧尾
            return ch;
        }
    }
    recv_flag = 0; //正常获取一个字节
    return ch;
}

/* 数据解析线程 */
static void data_parse(void)
{
    char rx_temp = 0;
    char rx_len = 0;
    char data_buf[30] = {0};

    while(1)
    {
        rx_temp = uart_get_char();
        if(rx_temp != '\n')
        {
            data_buf[(rx_len++)%30] = rx_temp;
        }
        else
        {
            rx_len = 0;
            rt_kprintf("uart1 received data is %s\r\n",data_buf);

            if(data_buf[0]=='#')
            {
                i = 1;
                x_mid = 0;
                while(data_buf[i]!= '*' && i<20)
                {
                    //rt_kprintf("Enter the mode");
                    x_mid = 10*x_mid;
                    bit_read = data_buf[i] - '0';
//                    bit_num = atoi(bit_read);
                    x_mid += bit_read;
                    i++;
                }
                while(data_buf[i]!= '&' &&i<20)
                {
                    class = (data_buf[i]) - '0';
                    i++;
                }
//                sprintf(str, "x_mid=%d\r\n", x_mid);
//                rt_kprintf(str);
            }
            memset(data_buf, 0, sizeof(data_buf));
        }

    }
}

static int uart1_function(void)
{
    rt_err_t ret = RT_EOK;
    /* 查找系统中的串口设备 */
    serial1 = rt_device_find(SAMPLE_UART_NAME);
    if(!serial1)
    {
        rt_kprintf("find %s failed!\n",SAMPLE_UART_NAME);
        return RT_ERROR;
    }

    /* 初始化信号量 */
    rt_sem_init(&rx_sem1, "rx_sem1", 0, RT_IPC_FLAG_FIFO);
    /* 以中断接收及轮询发送模式打开串口设备 */
    rt_device_open(serial1, RT_DEVICE_FLAG_INT_RX);
    /* 设置接收回调函数 */
    rt_device_set_rx_indicate(serial1, uart1_rx_ind);

    /* 创建 serial 线程 */
    rt_thread_t thread1 = rt_thread_create("thread_uart1", (void (*)(void *parameter))data_parse,
                                           RT_NULL, 1024, 24, 10);
    /* 创建成功则启动线程 */
    if (thread1 != RT_NULL)
    {
        rt_thread_startup(thread1);
    }
    else
    {
        ret = RT_ERROR;
    }
    return ret;

}

INIT_APP_EXPORT(uart1_function);

//char str_temp[50];
//void uart2_initial(void)
//{
//    serial2 = rt_device_find(SAMPLE_UART2_NAME);
//    if (!serial2)
//    {
//        rt_kprintf("find %s failed!\n", SAMPLE_UART2_NAME);
//        return RT_ERROR;
//    }
//
//}
//
//void uart2_send(void)
//{
//        rt_device_open(serial2, RT_DEVICE_FLAG_INT_RX);//RT_DEVICE_FLAG_INT_RX 0x100
//        sprintf(str_temp,"#%d.%d*%d.%d!%d.%d&\n", (int)temperature, (int)(temperature * 10) % 10,(int)humidity, (int)(humidity * 10) % 10,(int)(light)/10, (int)(light)%10);
//        rt_device_write(serial2, 0, str_temp, (sizeof(str_temp) - 1));
//        rt_device_close(serial2);
//        rt_thread_delay(100);
//}
