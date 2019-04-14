#include "shell.h"
/**
 * main - Simple Shell
 * @ac: Argument counter.
 * @av: Argument values.
 *
 * Return: 0 or -1 in failure.
 */
int main(int ac, char **av)
{
	char *shell_pharse;
	command_t **cmd_list = NULL; /* Command List */

	ac++;
	shell_pharse = isatty(STDIN_FILENO) ? "#cisfun$ " : NULL;
	while (1)
	{
		cmd_list = _prompt(av[0], shell_pharse); /* get commands from cmd_line */
		if (cmd_list)
		{
			if (!_fork(av[0], *cmd_list))
				error_handler(av[0], 102);
		}
		else
			error_handler(av[0], 103);
	}
	return (0);
}
