#include "shell.h"
/**
 * main - Simple Shell
 * @ac: Argument counter.
 * @av: Argument values.
 * Return: 0 or -1 in failure.
 */
int main(int ac, char **av)
{
	size_t i, cmd_amount, arg_amount, size = 0, buf_size = 512;
	char commands[buf_size], arguments[buf_size];
    char *comands_ptr = commands;
    char *arguments_ptr = arguments;

	while ((*(*av + size)) != '\0')
		size += 1;
	if (ac > 1)
	{
    	printf("%s", *av);
	}
	else
	{
		while (1)
		{
			/* printf("Buffer address: %p\n", (void *)line); */
			cmd_amount = _prompt(commands, &buf_size); /* get commands from cmd_line */
            printf("DEBUG: Command amount: %zu\n", cmd_amount);
            printf("DEBUG: Commands:\n");
            print_char_pointer_arr(commands, cmd_amount);
			if (cmd_amount)
			{
            for (i = 0; i < cmd_amount; i++)
				{
                    printf("DEBUG: Parsing command for argument s: ADDRESS-%p\n", (void *)commands[i]);
                    printf("DEBUG: Parsing command for arguments: OUT-%s\n", commands[i]);
                    arg_amount = _parser_arg((void *)commands[i], arguments, &buf_size); /*get arguments from command */
                    printf("DEBUG: Arguments amount: %zu\n", arg_amount);
					if (!_fork(arg_amount, arguments))
                        error_handler(*av, 102);	
				}
			}
			else
				error_handler(*av, 103);
		}
	}
	return (0);
}
