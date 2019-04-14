#include "shell.h"
/**
 * new_cmd_node - Creates a new node for command struct
 * @myself: my own name as shell.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
command_t *new_cmd_node(char *myself)
{
	command_t *cmd_node = NULL;

	cmd_node = malloc(sizeof(command_t));
	if (!cmd_node)
		error_handler(myself, 104);
	return (cmd_node);
}

void *add_token_to_cmd(char *myself, command_t cmd, size_t index
)
{
	char *token = NULL;

	cmd_node = malloc(sizeof(command_t));
	if (!cmd_node)
		error_handler(myself, 104);
	return (cmd_node);
}