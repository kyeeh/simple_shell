#include "shell.h"
/**
 * main - Simple Shell
 * @ac: Argument counter.
 * @av: Argument values.
 * Return: 0 or -1 in failure.
 */
int main(int ac, char **av)
{
	size_t cmd_amount, buff_size = 1024, size = 0, cmd_size = 512;
	char cmd_line[buff_size];
	char *commands[cmd_size];
	//char *cmds_ptr = cmd_line;

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
			cmd_amount = _prompt(cmd_line, buff_size, commands, cmd_size);
			if (cmd_amount)
			{
				if (_fork(cmd_amount, commands)) // just for one word commands
				{
					/* printf("Buffer address: %p\n", (void *)line); */
					
					
				}
				/* else
					error_handler(*av, 102); */
			}
			else
				error_handler(*av, 100);
		}
	}
	return (0);
}
