#include <logging/log.h>
#include <device.h>
#include "my_lib.h"

#define DT_DRV_COMPAT generic_my_driver

LOG_MODULE_REGISTER(MY_DRIVER, LOG_LEVEL_INF);

static int my_driver_init(const struct device *dev)
{
	LOG_INF("INIT! %d", my_lib_add_numbers(5, 5));
	return 0;
}


#define DEFINE_MY_DRIVER(inst) \
	DEVICE_DT_INST_DEFINE(inst, my_driver_init, NULL, \
		NULL, NULL, POST_KERNEL, \
		CONFIG_KERNEL_INIT_PRIORITY_DEVICE, NULL);

DT_INST_FOREACH_STATUS_OKAY(DEFINE_MY_DRIVER)

