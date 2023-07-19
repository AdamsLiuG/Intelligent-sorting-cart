#include "sensor.h"
#include <rtdbg.h>
#include <bh1750_collect.h>
static rt_thread_t bh1750_thread = RT_NULL;
static struct rt_mailbox bh1750_mb;
static char mb_pool[16];
#include <bh1750.h>
float light;
static rt_device_t dev = RT_NULL;

//static void bh1750_thread_entry(void *parameter)
//{
//    if (hdev)
//     {
//         bh1750_deinit(hdev);
//     }
//
//    hdev = bh1750_init("i2c3");
//
//    while(1)
//    {
//        rt_mb_send(&bh1750_mb,(rt_uint32_t)hdev);
//        light = bh1750_read_light(hdev);
//        rt_kprintf("read bh1750 sensor intensity: %4d.%d lux\n", (int)(light)/10, (int)(light)%10);
//        rt_thread_mdelay(5000);
//    }
//}

//static int bh1750_example(void)
//{
//    rt_err_t rt_err;
//
//    rt_err = rt_mb_init(&bh1750_mb,"bh1750_mb",&mb_pool[1],sizeof(mb_pool)/4,RT_IPC_FLAG_FIFO);
//    if(rt_err != RT_EOK)
//    {
//        LOG_D("init mailbox failed.\n");
//        return -1;
//    }
//
//    bh1750_thread = rt_thread_create("bh1750_thread",
//                            bh1750_thread_entry,
//                            RT_NULL,
//                            1024,
//                            18,
//                            10);
//   if(bh1750_thread != RT_NULL)
//   {
//        rt_thread_startup(bh1750_thread);
//   }
//
//   return 0;
//}
//
//INIT_APP_EXPORT(bh1750_example);

//bh1750_device_t get_bh1750_singleshot(void)
//{
//    if(rt_mb_recv(&bh1750_mb, (rt_ubase_t *)&dev, RT_WAITING_FOREVER) == RT_EOK)
//    {
//        return hdev;
//    }
//    else {
//        return RT_NULL;
//    }
//}

static void bh1750_thread_entry(void *parameter)
{

    struct rt_sensor_data data;
    rt_size_t res;

    /* 查找bh1750传感器  */
    dev = rt_device_find("li_bh1750");
    if (dev == RT_NULL)
    {
        LOG_D("Can't find device:li_bh1750\n");
        return;
    }

    /* 以只读模式打开bh1750 */
    if (rt_device_open(dev, RT_DEVICE_FLAG_RDONLY) != RT_EOK)
    {
        LOG_D("open device failed!");
        return;
    }

    while(1)
    {
        /* 从传感器读取一个数据 */
        res = rt_device_read(dev, 0, &data, 1);
        if (1 != res)
        {
            LOG_D("read data failed!size is %d", res);
        }
        else
        {
            rt_mb_send(&bh1750_mb,(rt_uint32_t)dev);
            light = data.data.light;
//            rt_kprintf("light:%4d.%d lux\n", (int)(light)/10, (int)(light)%10);
        }
        rt_thread_mdelay(5000);
    }
}

static int bh1750_example(void)
{
//    rt_thread_t tid;    /* 线程句柄 */

    rt_err_t rt_err;

    rt_err = rt_mb_init(&bh1750_mb,"bh1750_mb",&mb_pool[0],sizeof(mb_pool)/4,RT_IPC_FLAG_FIFO);
    if(rt_err != RT_EOK)
    {
        LOG_D("init mailbox failed.\n");
        return -1;
    }

    bh1750_thread = rt_thread_create("bh1750_thread",
                            bh1750_thread_entry,
                            RT_NULL,
                            1024,
                            21,
                            10);
   if(bh1750_thread != RT_NULL)
   {
       /* 线程创建成功，启动线程 */
        rt_thread_startup(bh1750_thread);
   }

   return 0;
}

INIT_APP_EXPORT(bh1750_example);
