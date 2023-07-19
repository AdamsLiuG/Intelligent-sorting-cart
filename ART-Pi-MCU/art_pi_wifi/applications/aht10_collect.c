#include "sensor_asair_aht10.h"
#include "sensor.h"
#include <rtdbg.h>
#include <aht10_collect.h>
#define AHT10_I2C_BUS  "i2c3"
int rt_hw_aht10_port(void)
{
    struct rt_sensor_config cfg;
    cfg.intf.dev_name  = AHT10_I2C_BUS;
    cfg.intf.user_data = (void *)AHT10_I2C_ADDR;
    rt_hw_aht10_init("aht10", &cfg);
    return RT_EOK;
}
INIT_ENV_EXPORT(rt_hw_aht10_port);

// AHT10温湿度采集
#include "aht10.h"
/* 定义一个温湿度采集线程句柄结构体指针 */
static rt_thread_t aht10_thread = RT_NULL;
static struct rt_mailbox aht10_mb;
static char mb_pool[16];
aht10_device_t dev;
float humidity, temperature;
/* 温湿度采集线程入口函数*/
aht10_device_t get_aht10_singleshot(void)
{
    if(rt_mb_recv(&aht10_mb, (rt_ubase_t *)&dev, RT_WAITING_FOREVER)==RT_EOK)
    {
        return dev;
    }
    else {
        return RT_NULL;
    }
}
static void aht10_thread_entry(void *parameter)
{
//    rt_err_t res;

    rt_hw_aht10_port();
    dev = aht10_init(AHT10_I2C_BUS);
    if (dev == RT_NULL)
    {
        LOG_D(" The sensor initializes failure");
        return ;
    }
    else
    {
        LOG_D(" The sensor initializes ok!");
    }
    while (1)
    {

        /* read humidity 采集湿度 */
        rt_mb_send(&aht10_mb, (rt_uint32_t)dev);
        humidity = aht10_read_humidity(dev);
        LOG_D("HELLO RT-THREAD");
//        rt_kprintf("humidity   : %d.%d %%\n", (int)humidity, (int)(humidity * 10) % 10); /* former is integer and behind is decimal */
        /* read temperature 采集温度 */
        temperature = aht10_read_temperature(dev);
//        rt_kprintf("temperature: %d.%d \n", (int)temperature, (int)(temperature * 10) % 10); /* former is integer and behind is decimal */
        rt_thread_mdelay(5000);
    }
}
static int app_aht10_init(void)
{
    rt_err_t rt_err;
    /* 创建温湿度采集线程*/

    rt_err = rt_mb_init(&aht10_mb, "aht10_mb", &mb_pool[0], sizeof(mb_pool)/4, RT_IPC_FLAG_FIFO);
    if(rt_err != RT_EOK)
    {
        LOG_D("init mailbox failed.\n");
        return -1;
    }
    aht10_thread = rt_thread_create("aht10 thread",     /* 线程的名称 */
                                aht10_thread_entry, /* 线程入口函数 */
                                RT_NULL,            /* 线程入口函数的参数   */
                                1024,                /* 线程栈大小，单位是字节  */
                                25,                 /* 线程的优先级，数值越小优先级越高*/
                                10);                /* 线程的时间片大小 */
    /* 如果获得线程控制块，启动这个线程 */
    if (aht10_thread != RT_NULL)
        rt_err = rt_thread_startup(aht10_thread);
}
INIT_APP_EXPORT(app_aht10_init);
