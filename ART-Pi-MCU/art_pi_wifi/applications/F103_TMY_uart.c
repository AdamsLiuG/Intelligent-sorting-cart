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
#include <F103_TMY_uart.h>
#define SAMPLE_UART_NAME       "uart5"
struct rt_semaphore      rx_sem5;
static rt_device_t          serial5;

#define THREAD_PRIORITY         2
#define THREAD_STACK_SIZE       1024
#define THREAD_TIMESLICE        5

int j = 0;
char str[30];
float angle;
int bit_read;
float bit_Point;

/* 接收数据回调函数 */
static rt_err_t uart5_rx_ind(rt_device_t dev, rt_size_t size)
{
    /* 串口接收到数据后产生中断，调用此回调函数，然后发送接收信号量 */
    if (size > 0)
    {
        rt_sem_release(&rx_sem5);
    }
    return RT_EOK;
}

static rt_err_t uart_get_char(void)
{
    char ch;
    static uint8_t recv_flag = 1;

    while (rt_device_read(serial5, 0, &ch, 1) == 0)
    {
        rt_sem_control(&rx_sem5, RT_IPC_CMD_RESET, RT_NULL);
        if(recv_flag)
        {
            rt_sem_take(&rx_sem5, RT_WAITING_FOREVER);
        }
        else if(-RT_ETIMEOUT == rt_sem_take(&rx_sem5, 100))//超时100ms未获得串口数据  100是根据时钟节拍来定 节拍单位是1/RT_TICK_PER_SECOND 秒
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
//            rt_kprintf("uart5 received data is %s\r\n",data_buf);

            if(data_buf[0]=='#')
            {
//#%.1f&\n
                j = 1;
                angle = 0;
                while(data_buf[j]!= '&' && j<20)
                {
                    if(data_buf[j]!='.')
                    {
                        angle = 10 * angle;
                        bit_read = data_buf[j] - '0';
                        angle += bit_read;
                    }
                    else if(data_buf[j] == '.')
                    {
                        j++;
                        bit_Point = (float)(data_buf[j] - '0')/10;
                        angle = angle + bit_Point;
                    }
                    j++;
                }
//                sprintf(str, "angle=%.1f\r\n", angle);
//                rt_kprintf(str);
            }
            memset(data_buf, 0, sizeof(data_buf));
        }
    }
}

static int uart5_function(void)
{
    rt_err_t ret = RT_EOK;
    /* 查找系统中的串口设备 */
    serial5 = rt_device_find(SAMPLE_UART_NAME);
    if(!serial5)
    {
        rt_kprintf("find %s failed!\n",SAMPLE_UART_NAME);
        return RT_ERROR;
    }

    /* 初始化信号量 */
    rt_sem_init(&rx_sem5, "rx_sem5", 0, RT_IPC_FLAG_FIFO);
    /* 以中断接收及轮询发送模式打开串口设备 */
    rt_device_open(serial5, RT_DEVICE_FLAG_INT_RX);
    /* 设置接收回调函数 */
    rt_device_set_rx_indicate(serial5, uart5_rx_ind);

    /* 创建 serial 线程 */
    rt_thread_t thread5 = rt_thread_create("thread_uart5", (void (*)(void *parameter))data_parse,
                                           RT_NULL, 1024, 24, 10);
    /* 创建成功则启动线程 */
    if (thread5 != RT_NULL)
    {
        rt_thread_startup(thread5);
    }
    else
    {
        ret = RT_ERROR;
    }
    return ret;
}
INIT_APP_EXPORT(uart5_function);




