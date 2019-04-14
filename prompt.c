#include "shell.h"
/**
 * _prompt - prompt actions
 * @cmds: String array to storage commands
 * cmd_size: size of cmds.
 */
command_t **_prompt(void)
{
	size_t char_amount, buff_size = 0;
	char *cmd_line = NULL;
	command_t *cmd_node = NULL;
	command_t **cmd_list = &cmd_node; /* Command List */

	write(STDOUT_FILENO, "#cisfun$ ", 9);
	char_amount = getline(&cmd_line, &buff_size, stdin); /* Insert new _getline */
	if (cmd_line)
	{
		*cmd_list = _parser_cmd(cmd_line);
		free(cmd_line);
		cmd_line = NULL;		
		return (cmd_list);
	}
	return (0);
}
