#include "shell.h"
/**
 * _prompt - write prompt and read a command line.
 * @myself: String for prompt init.
 * @shell_phrase: String for prompt init.
 * @hist: History head list.
 *
 * Return: NULL or pointer to command list.
 */
command_t **_prompt(char *myself, char *shell_phrase, history_t **hist)
{
	size_t buff_size = 0;
	ssize_t char_amount = 0;
	char *cmd_line = NULL;
	command_t *cmd_node = NULL;
	command_t **cmd_list = &cmd_node; /* Command List */
	int history_status;

	char_amount = _strlen(shell_phrase);
	if (shell_phrase)
		write(STDOUT_FILENO, shell_phrase, char_amount);
	/* ToDO: Insert new _getline */
	char_amount = getline(&cmd_line, &buff_size, stdin);
/* Insert into history here */
	if ((history_status = add_nodeint(hist, cmd_line)) < 0)
		printf("History error in add node\n"); /* Insert error here */
	/* print_listint(*hist); */
/****            ***********/
	printf("This is char_amount %s\n", cmd_line);
	if (char_amount < 0)
	{
		fflush(stdin);
		cmd_list = NULL;
	}
	else
	{
		*cmd_list = _parser_cmd(myself, cmd_line);
		/* Verify the commands */
		/* free(cmd_line);
		* cmd_line = NULL; */
		return (cmd_list);
	}
	return (NULL);
}
