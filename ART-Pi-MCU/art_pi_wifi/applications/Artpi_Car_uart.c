/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-07-08     Adams Liu    first version
 */
#include <rtthread.h>
#include <Artpi_Car_uart.h>
#include <math.h>

#define DATA_CMD_END  '&'
#define DATA_MAXLEN    30
#define SAMPLE_UART_NAME       "uart6"       /* 闇�瑕佹搷浣滅殑璁惧 */
static rt_device_t serial6;
struct rt_semaphore      rx_sem6;

char ST[20]; //直行模式
char LS[20]; //左前进模式
char RS[20]; //右前进模式
char ROT[20]; //微调模式
char BACK[20]; // 返航模式

//char LTUNE[] = "$SMODE7!"; // 左平移微调模式
//char RTUNE[] = "$SMODE8!"; // 右平移微调模式
char CLAMP_APPLE[] = "$SMODE5!"; // 夹取类别0(苹果)
char CLAMP_PITAYA[] = "$SMODE6!"; // 夹取类别1(火龙果)
char CLAMP_NOTHING[] = "$SMODE7!"; // 未识别到水果，不夹取


extern int init_flag;
int stop_flag;
int clamp_flag;
int finetune_flag;
int back_flag;
int num_apple = 0;
int num_pitaya = 0;
int count_apple = 0;
int count_pitaya = 0;

extern int class;
extern int x_mid;
extern float angle;
extern float angle_init;

float angle_now;
float angle_final;
float angle_last;
float angle_diff;
float angle_diff1;
float angle_diff2;
int angle_int;
float angle_thres_stright = 1.0;
float angle_thres_stop = 1.0;

char str_differ[30];
static rt_err_t uart6_rx_ind(rt_device_t dev, rt_size_t size)
{
    if (size > 0)
    {
        rt_sem_release(&rx_sem6);
    }
    return RT_EOK;
}

static rt_err_t uart_get_char(void)
{
    char ch;
    static uint8_t recv_flag = 1;

    while (rt_device_read(serial6, 0, &ch, 1) == 0)
    {
        rt_sem_control(&rx_sem6, RT_IPC_CMD_RESET, RT_NULL);
        if(recv_flag)
        {
            rt_sem_take(&rx_sem6, RT_WAITING_FOREVER);
        }
        else if(-RT_ETIMEOUT == rt_sem_take(&rx_sem6, 100))//超时100ms未获得串口数据  100是根据时钟节拍来定 节拍单位是1/RT_TICK_PER_SECOND 秒
        {
            recv_flag = 1; //收完一帧
            ch = '\n'; //也可以用别的当伪帧尾
            return ch;
        }
    }
    recv_flag = 0; //正常获取一个字节
    return ch;
}

// 数据解析线程
static void data_parse(void)
{
    char rx_temp;
    char data_buf[DATA_MAXLEN];
    static char i = 0;

    while(1)
    {
        rx_temp = uart_get_char();

        if(rx_temp == DATA_CMD_END)//结束符为&，表示结束
        {
            if(data_buf[i-1]=='A')//微调模式
            {
                rt_kprintf(data_buf[i-1]);
                init_flag = 0;
                finetune_flag = 1;
            }
            if(data_buf[i-1]=='B')//开始识别
            {
                finetune_flag = 0;
                clamp_flag = 1;
            }
            if(data_buf[i-1]=='C')//正在夹取
            {
               clamp_flag = 0;
               num_apple = 0;
               num_pitaya = 0;
            }
            if(data_buf[i-1]=='D')//夹取完成
            {
               rt_kprintf("---------------D is transmitted!--------------\n");
               clamp_flag = 0;
               back_flag = 1;
            }
            i = 0;

            continue;
        }
        i = (i >= DATA_MAXLEN-1) ? DATA_MAXLEN-1 : i;
        data_buf[i++] = rx_temp;
    }
}

static int uart6_function(void)
{
    char str[] = "hello RT-Thread s!\r\n";
    rt_err_t ret = RT_EOK;
    serial6 = rt_device_find(SAMPLE_UART_NAME);
    if(!serial6)
    {
        rt_kprintf("find %s failed!\n",SAMPLE_UART_NAME);
        return RT_ERROR;
    }

    /* 初始化信号量 */
    rt_sem_init(&rx_sem6, "rx_sem6", 0, RT_IPC_FLAG_FIFO);
    /* 以中断接收及轮询发送模式打开串口设备 */
    rt_device_open(serial6, RT_DEVICE_FLAG_INT_RX);
    /* 设置接收回调函数 */
    rt_device_set_rx_indicate(serial6, uart6_rx_ind);

    /* 创建 serial 线程 */
    rt_thread_t thread6 = rt_thread_create("thread_uart6", (void (*)(void *parameter))data_parse,
                                           RT_NULL, 1024, 20, 10);
    /* 创建成功则启动线程 */
    if (thread6 != RT_NULL)
    {
        rt_thread_startup(thread6);
    }
    else
    {
        ret = RT_ERROR;
    }
    return ret;

}

INIT_APP_EXPORT(uart6_function);

void uart6_initial(void)
{
    /* 鏌ユ壘绯荤粺涓殑涓插彛璁惧 */
    serial6 = rt_device_find(SAMPLE_UART_NAME);
    if (!serial6)
    {
        rt_kprintf("find %s failed!\n", SAMPLE_UART_NAME);
        return RT_ERROR;
    }
//    return 0;
}

int uart6_action()
{
    /* 行进模式 */
    if (init_flag == 1 && finetune_flag == 0 && clamp_flag == 0 && back_flag == 0){
        angle_now = angle; // 读入新的陀螺仪角度

        /* 获取新角度与初始角度的差值 */
        angle_diff = angle_now - angle_init;
//        sprintf(str_differ, "differ=%.1f\r\n", angle_diff);
//        rt_kprintf(str_differ);
        angle_int = (int)angle_diff;
        rt_device_open(serial6, RT_DEVICE_FLAG_INT_RX);
        sprintf(ST,"$SMODE%d-%d!",1,angle_int);
        rt_kprintf(ST);
        rt_device_write(serial6, 0, ST, (sizeof(ST) - 1));
        rt_thread_mdelay(50);
        rt_device_close(serial6);
    }

    /* 到达传送带并开启微调模式 */
    if (init_flag == 0 && finetune_flag == 1 && clamp_flag == 0 && back_flag == 0){
        angle_now = angle; // 读入新的陀螺仪角度

        /* 获取新角度与初始角度的差值 */
        angle_diff = angle_now - angle_init;
        /* 左旋转微调以回到初始角度 */
        sprintf(str_differ, "differ=%.1f\r\n", angle_diff);
        rt_kprintf(str_differ);
        angle_int = (int)angle_diff;
        rt_device_open(serial6, RT_DEVICE_FLAG_INT_RX);
        sprintf(ROT,"$SMODE%d-%d!",2,angle_int);
        rt_kprintf(ROT);
        rt_device_write(serial6, 0, ROT, (sizeof(ROT) - 1));
        rt_thread_mdelay(50);
        rt_device_close(serial6);

//        else if ((angle_diff < angle_thres_stop) && (angle_diff > (angle_thres_stop*(-1)))){
//            finetune_flag = 0;
//            clamp_flag = 1;
//        }
    }
    /* 夹取水果模式 */
    else if (init_flag == 0 && finetune_flag == 0 && clamp_flag == 1 && back_flag == 0){
        /* 识别结果为苹果 */
        if (class == 0){
            class = 2;
            num_pitaya = 0;
            num_apple++;
            if (num_apple == 2){
                num_apple = 0;
                rt_device_open(serial6, RT_DEVICE_FLAG_INT_RX);
                rt_device_write(serial6, 0, CLAMP_APPLE, (sizeof(CLAMP_APPLE) - 1));
                rt_kprintf(CLAMP_APPLE);
                rt_thread_mdelay(50);
                rt_device_close(serial6);
            }
            else {
                rt_device_open(serial6, RT_DEVICE_FLAG_INT_RX);
                rt_device_write(serial6, 0, CLAMP_NOTHING, (sizeof(CLAMP_NOTHING) - 1));
                rt_thread_mdelay(50);
                rt_device_close(serial6);
            }
        }

        /* 识别结果为火龙果 */
        else if (class == 1){
            class = 2;
            num_apple = 0;
            num_pitaya++;
            if (num_pitaya == 2){
                num_pitaya = 0;
                rt_device_open(serial6, RT_DEVICE_FLAG_INT_RX);
                rt_device_write(serial6, 0, CLAMP_PITAYA, (sizeof(CLAMP_PITAYA) - 1));
                rt_thread_mdelay(50);
                rt_device_close(serial6);
            }
            else {
                rt_device_open(serial6, RT_DEVICE_FLAG_INT_RX);
                rt_device_write(serial6, 0, CLAMP_NOTHING, (sizeof(CLAMP_NOTHING) - 1));
                rt_thread_mdelay(50);
                rt_device_close(serial6);
            }

        }

    }

    /* 返航模式 */
    else if (back_flag == 1){
//        rt_kprintf("----------------------Back!-----------------------\n");
//        rt_device_open(serial6, RT_DEVICE_FLAG_INT_RX);
//        rt_device_write(serial6, 0, BACK, (sizeof(BACK) - 1));
//        rt_thread_mdelay(200);
//        rt_device_close(serial6);
//        back_flag = 0;
        angle_now = angle; // 读入新的陀螺仪角度
        /* 获取新角度与初始角度的差值 */
        angle_diff = angle_now - angle_init;
//        sprintf(str_differ, "differ=%.1f\r\n", angle_diff);
//        rt_kprintf(str_differ);
        angle_int = (int)angle_diff;
        rt_device_open(serial6, RT_DEVICE_FLAG_INT_RX);
        sprintf(BACK,"$SMODE%d-%d!",8,angle_int);
        rt_kprintf(BACK);
        rt_device_write(serial6, 0, BACK, (sizeof(BACK) - 1));
        rt_thread_mdelay(50);
        rt_device_close(serial6);
        back_flag = 0;
    }
}
