#include "shell.h"
/**
 * _prompt - write prompt and read a command line.
 * @shell_phrase: String for prompt init.
 *
 * Return: NULL or pointer to command list.
 */
command_t **_prompt(char *shell_phrase)
{
	size_t buff_size = 0;
	ssize_t char_amount = 0;
	char *cmd_line = NULL;
	command_t *cmd_node = NULL;
	command_t **cmd_list = &cmd_node; /* Command List */

	char_amount = _strlen(shell_phrase);
	if (shell_phrase)
		write(STDOUT_FILENO, shell_phrase, char_amount);
	/* ToDO: Insert new _getline */
	char_amount = getline(&cmd_line, &buff_size, stdin);
	if (*cmd_line == '\n' || char_amount < 0)
	{
		fflush(stdin);
		cmd_list = NULL;
	}
	else
	{
		*cmd_list = _parser_cmd(cmd_line);
		free(cmd_line);
		cmd_line = NULL;
		return (cmd_list);
	}
	return (NULL);
}
