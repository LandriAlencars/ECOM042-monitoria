/*******************************************************************
 * @file commands.c
 *
 * @brief Concrete commands. Adding a new command only touches this
 *        file (and the table in main.c), never the dispatcher.
 * @author Landri Alencar (ljas@ic.ufal.br)
 * @version 0.1
 * @date 01/10/2026
 *******************************************************************/

#include <errno.h>

#include <zephyr/kernel.h>

#include "commands.h"

static int led_on_execute(void *ctx)
{
	struct app_state *dev = ctx;

	if (dev == NULL) {
		return -EINVAL;
	}

	dev->led_on = true;
	printk("LED on\n");

	return 0;
}

static int led_off_execute(void *ctx)
{
	struct app_state *dev = ctx;

	if (dev == NULL) {
		return -EINVAL;
	}

	dev->led_on = false;
	printk("LED off\n");

	return 0;
}

static int blink_execute(void *ctx)
{
	struct app_state *dev = ctx;

	if (dev == NULL) {
		return -EINVAL;
	}

	dev->led_on = !dev->led_on;
	dev->blink_count++;
	printk("LED toggled (blink #%u)\n", dev->blink_count);

	return 0;
}

static int status_execute(void *ctx)
{
	const struct app_state *dev = ctx;

	if (dev == NULL) {
		return -EINVAL;
	}

	printk("status: led=%s blinks=%u\n", dev->led_on ? "on" : "off", dev->blink_count);

	return 0;
}

const struct command cmd_led_on = {.name = "led_on", .execute = led_on_execute};
const struct command cmd_led_off = {.name = "led_off", .execute = led_off_execute};
const struct command cmd_blink = {.name = "blink", .execute = blink_execute};
const struct command cmd_status = {.name = "status", .execute = status_execute};
