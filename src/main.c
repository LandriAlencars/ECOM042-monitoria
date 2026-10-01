/*******************************************************************
 * @file main.c
 *
 * @brief Main file.
 * @author João Matheus Nascimento Dias (jmnd@ic.ufal.br)
 * @version 0.1
 * @date 26/08/2026
 *******************************************************************/

#include <errno.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>

#include "command.h"
#include "commands.h"

static const struct command *const command_table[] = {
	&cmd_led_on,
	&cmd_led_off,
	&cmd_blink,
	&cmd_status,
};

int main(void)
{
	struct app_state dev = {0};
	const char *requests[] = {"led_on", "status", "blink", "blink", "status", "reboot"};

	for (size_t i = 0; i < ARRAY_SIZE(requests); i++) {
		int ret = command_dispatch(command_table, ARRAY_SIZE(command_table), requests[i],
					   &dev);

		if (ret == -ENOENT) {
			printk("error: unknown command '%s'\n", requests[i]);
		} else if (ret < 0) {
			printk("error: command '%s' failed (%d)\n", requests[i], ret);
		}
	}

	return 0;
}
