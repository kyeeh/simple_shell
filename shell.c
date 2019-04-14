#include "shell.h"
/**
 * main - Simple Shell
 * @ac: Argument counter.
 * @av: Argument values.
 * Return: 0 or -1 in failure.
 */
int main(int ac, char **av)
{
	char *shell_pharse;
	/* size_t cmd_amount = 0, size = 0; */
	command_t **cmd_list = NULL; /* Command List */
	/*
	while ((*(*av + size)) != '\0')
		size += 1;
	if (ac > 1)
	{
    	print_char_pointer_arr(av, ac);
	}
	*/
	shell_pharse = isatty(STDIN_FILENO) ? "#cisfun$ " : NULL;
	while (1)
	{	
		cmd_list = _prompt(shell_pharse); /* get commands from cmd_line */
		if (cmd_list)
		{
			if (!_fork(av[0], *cmd_list))
				error_handler(av[0],102);
		}
		else
			error_handler(av[0], 103);
	}

	return (0);
}
