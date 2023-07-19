#ifndef __AHT10_COLLECT_H__
#define __AHT10_COLLECT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "sensor_asair_aht10.h"
#include "sensor.h"
#include <rtdbg.h>

int rt_hw_aht10_port(void);
aht10_device_t get_aht10_singleshot(void);
static int app_aht10_init(void);
static void aht10_thread_entry(void *parameter);

#ifdef __cplusplus
}
#endif
#endif
