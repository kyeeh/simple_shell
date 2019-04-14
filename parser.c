#include "shell.h"
/**
 * _parser_cmd - Parses a simple command from prompt.
 * @cmd_line: command line to be parsed from prompt.
 */
command_t *_parser_cmd(char *cmd_line)
{
	unsigned int i = 0;
	char *cmd_str = NULL;
	/* const char *cmd_sep = ";|"; */
	const char *cmd_sep = " ";
	command_t *cmd_node = NULL;

	cmd_str = strtok(cmd_line, cmd_sep); /* get the first token */
	if (cmd_str)
	{
		cmd_node = malloc(sizeof(command_t));
		if (!cmd_node)
			error_handler(104);
		cmd_node->command[i] = cmd_str;
		cmd_node->next = NULL;
		printf( "Token(%u) %s\n", i, cmd_node->command[0]);
		while(cmd_str != NULL) {/* walk through other tokens */
			cmd_str == NULL ? i : i++;
			cmd_str = strtok(NULL, cmd_sep);
			cmd_node->command[i] = cmd_str;
			printf( "Token(%u) %s\n", i, cmd_node->command[i]);
		}
	}
	return (cmd_node); 
}
