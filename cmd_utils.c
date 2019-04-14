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

/**
 * add_tok_to_cmd - Add Token from cmd line to cmd node
 * @sh: my own name as shell.
 * @cmd_node: Command node to be updated.
 * @index: position to add token.
 * @token: to be added.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void *add_tok_to_cmd(char *sh, command_t *cmd_node, size_t index, char *token)
{
	size_t tok_len;
	char *str = NULL;

	tok_len = _strlen(token);
	cmd_node->command[index] = malloc(sizeof(char) * tok_len);
	if (!cmd_node->command[index])
		error_handler(sh, 104);
	cmd_node->command[index] = token;	
	return (cmd_node);
}
