/*******************************************************************
 * @file commands.h
 *
 * @brief Concrete commands and the receiver they act on.
 * @author Landri Alencar (ljas@ic.ufal.br)
 * @version 0.1
 * @date 01/10/2026
 *******************************************************************/

#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdbool.h>

#include "command.h"

/**
 * @brief Receiver: state of the (simulated) device the commands act on.
 */
struct app_state {
	bool led_on;
	unsigned int blink_count;
};

extern const struct command cmd_led_on;
extern const struct command cmd_led_off;
extern const struct command cmd_blink;
extern const struct command cmd_status;

#endif /* COMMANDS_H */
