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

	error_handler_set_default(ac, *av);
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
		/* printf("Buffer address: %p\n", (void *)line); */
		cmd_list = _prompt(shell_pharse); /* get commands from cmd_line */
		/*printf("DEBUG: Command amount: %zu\n", cmd_amount);
		printf("DEBUG: Commands:\n");
		print_char_pointer_arr(commands, cmd_amount);*/
		if (cmd_list)
		{
			if (!_fork(*cmd_list))
				error_handler(102);			
		/*
		for (i = 0; i < cmd_amount; i++)
			{
				printf("DEBUG: Parsing command for argument s: ADDRESS-%p\n", (void *)commands[i]);
				printf("DEBUG: Parsing command for arguments: OUT-%s\n", commands[i]);
				arg_amount = _parser_arg((void *)commands[i], arguments, &buf_size); get arguments from command 
				printf("DEBUG: Arguments amount: %zu\n", arg_amount);
				if (!_fork(arg_amount, arguments))
					error_handler(102);
			}*/
		}
		else
			error_handler(103);
	}

	return (0);
}
