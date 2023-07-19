/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-07-08     Adams Liu    first version
 */

#ifndef APPLICATIONS_ToF407_UART_2_H_
#define APPLICATIONS_ToF407_UART_2_H_
#include <rtthread.h>
#include "rtconfig.h"
#include <rtdevice.h>
#include "drv_common.h"

//void uart_initial(void);
//void uart_send(void);

//static rt_err_t uart5_rx_ind(rt_device_t dev, rt_size_t size);
//
static rt_err_t uart_get_char(void);
static void data_parse(void);
int uart5_function(void);
#endif

