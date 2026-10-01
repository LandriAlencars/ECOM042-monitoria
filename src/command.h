/*******************************************************************
 * @file command.h
 *
 * @brief Generic command interface (Command Pattern) and dispatcher.
 * @author Landri Alencar (ljas@ic.ufal.br)
 * @version 0.1
 * @date 01/10/2026
 *******************************************************************/

#ifndef COMMAND_H
#define COMMAND_H

#include <stddef.h>

/**
 * @brief A command knows how to execute itself.
 *
 * The dispatcher only sees this interface, never the concrete commands.
 */
struct command {
	/** Name used to look the command up in the table. */
	const char *name;
	/** Action executed by the command, applied over @p ctx. */
	int (*execute)(void *ctx);
};

/**
 * @brief Finds the command named @p name in @p table and executes it.
 *
 * @param[in]     table Table of pointers to commands.
 * @param[in]     count Number of entries in @p table.
 * @param[in]     name  Name of the command to execute.
 * @param[in,out] ctx   Context (receiver) passed to the command.
 *
 * @retval value returned by the command's execute().
 * @retval -EINVAL if @p table or @p name is NULL.
 * @retval -ENOENT if no command named @p name exists in @p table.
 */
int command_dispatch(const struct command *const *table, size_t count, const char *name, void *ctx);

#endif /* COMMAND_H */
