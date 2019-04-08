#include "shell.h"
/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{

	char *line_read;

	/*Provisional void for the unused variables*/
	(void)line_read;
	(void)av;
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
		  line_read = read_line();
	}
	return (0);
}
