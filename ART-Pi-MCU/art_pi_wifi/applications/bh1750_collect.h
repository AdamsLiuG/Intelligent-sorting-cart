#ifndef __BH1750_COLLECT_H__
#define __BH1750_COLLECT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "sensor.h"
#include <rtdbg.h>
#include <bh1750.h>

static void bh1750_thread_entry(void *parameter);
static int bh1750_example(void);
#ifdef __cplusplus
}
#endif
#endif
