/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-09-02     RT-Thread    first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#include "Artpi_Car_uart.h"

#define LED_PIN GET_PIN(I, 8)

int init_flag;
extern float angle;
float angle_init;
extern float angle_last;
extern void wlan_autoconnect_init(void);
char str[30];
char str1[30];
int main(void)
{
    angle_init = angle;
    angle_last = angle_init;
    init_flag = 1;
    uart6_initial();
    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);

    /* init Wi-Fi auto connect feature */
    wlan_autoconnect_init();
    /* enable auto reconnect on WLAN device */
    rt_wlan_config_autoreconnect(RT_TRUE);

    while(rt_wlan_is_connected() != 1)
    {
        rt_thread_mdelay(10);
    }
    rt_kprintf("network is ok!\n");

    rt_thread_mdelay(1000);
    ali_mqtt_init();
    while(1)
    {
//        rt_pin_write(LED_PIN, PIN_HIGH);
//        rt_thread_mdelay(500);
//        rt_pin_write(LED_PIN, PIN_LOW);
        rt_thread_mdelay(50);
        uart6_action();
    }
    return RT_EOK;
}

#include "stm32h7xx.h"
static int vtor_config(void)
{
    /* Vector Table Relocation in Internal QSPI_FLASH */
    SCB->VTOR = QSPI_BASE;
    return 0;
}
INIT_BOARD_EXPORT(vtor_config);


