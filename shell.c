#include "shell.h"
/**
 * main - Simple Shell
 * @ac: Argument counter.
 * @av: Argument values.
 * Return: 0 or -1 in failure.
 */
int main(int ac, char **av)
{
  size_t linelen, size = 0, buff_size = 1024;
  char line[1024];

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
			linelen = _prompt(line, buff_size);
			if (linelen > 0)
			{
				if (_fork(line, av) < 0)
				{
					/* printf("Buffer address: %p\n", (void *)line); */
					error_handler(*av, size, 101);
					
				}
			}
			else
				error_handler(*av, size, 100);
		}
	}
	return (0);
}
