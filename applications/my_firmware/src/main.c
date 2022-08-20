#include <zephyr.h>
#include <device.h>
#include <sys/printk.h>
#include <logging/log.h>

LOG_MODULE_REGISTER(MAIN, LOG_LEVEL_INF);

void main(void)
{
	const struct device *dev_mine = DEVICE_DT_GET(DT_NODELABEL(my_driver_0));

	if (!device_is_ready(dev_mine)) {
		LOG_ERR("My device is not ready!");
	}

	while (true) {
		printk("hello!");
		k_sleep(K_MSEC(500));
	}
}
