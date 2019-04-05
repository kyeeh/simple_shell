#include "shell.h"
/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	size_t linelen, buff_size = 1024;
	char line[buff_size];
	char *lptr = line;

	if (ac > 1)
	{
		while (0)
		{
			/* read shell script - no iterative */
		}
	}
	else
	{
		while (1)
		{
			write(STDOUT_FILENO, "$", 1);
			linelen = getline(&lptr, &buff_size, stdin);
			
			while (*line != EOF)
			{

			}
		}
	}
	return (0);
}
