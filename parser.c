#include "shell.h"
/**
 * _parser_cmd - Parses a simple command from prompt.
 * @cmd_line: command line to be parsed from prompt.
 * @myself: my own name as shell.
 *
 * Return: NULL or pointer to command node
 */
command_t *_parser_cmd(char *myself, char *cmd_line)
{
	size_t i = 0;
	char *cmd_str = NULL;
	/* const char *cmd_sep = ";|"; */
	const char *arg_sep = " ";
	command_t *cmd_node = NULL;

	cmd_str = strtok(cmd_line, arg_sep); /* get the first token */
	if (cmd_str)
	{
		cmd_node = malloc(sizeof(command_t));
		if (!cmd_node)
			error_handler(myself, 104);
		cmd_node->command[i] = cmd_str;
		cmd_node->next = NULL;
		while (cmd_str != NULL)
		{ /* walk through other tokens */
			cmd_str == NULL ? i : i++;
			cmd_str = strtok(NULL, arg_sep);
			cmd_node->command[i] = cmd_str;
		}
	}
	return (cmd_node);
}
