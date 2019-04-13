#include "shell.h"
/**
 * _prompt - prompt actions
 * @cmds: String array to storage commands
 * cmd_size: size of cmds.
 */
char * _prompt(char *cmds[], size_t *cmd_size)
{
	size_t buff_size = 1024;
    char cmd_line[buff_size];
    char *cmd_ptr = NULL;

	write(STDOUT_FILENO, "#cisfun$ ", 9);
	getline(&cmd_ptr, &buff_size, stdin); /* Insert new _getline */

	return (cmd_ptr);
	/* return (_parser_cmd(cmd_line, cmds, cmd_size)); */
}
