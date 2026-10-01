/*******************************************************************
 * @file command.c
 *
 * @brief Generic dispatcher: knows no concrete command.
 * @author Landri Alencar (ljas@ic.ufal.br)
 * @version 0.1
 * @date 01/10/2026
 *******************************************************************/

#include <errno.h>
#include <string.h>

#include "command.h"

int command_dispatch(const struct command *const *table, size_t count, const char *name, void *ctx)
{
	if (table == NULL || name == NULL) {
		return -EINVAL;
	}

	for (size_t i = 0; i < count; i++) {
		const struct command *cmd = table[i];

		if (cmd != NULL && cmd->execute != NULL && strcmp(cmd->name, name) == 0) {
			return cmd->execute(ctx);
		}
	}

	return -ENOENT;
}
