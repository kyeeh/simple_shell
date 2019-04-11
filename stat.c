
#include "shell.h"
/**
 * main - stat of a file
 *
 * Return: 1 on sucess, -1 on failure.
 */
int _stat(char *av)
{
	struct stat st;

	printf("DEBUG: Stat for %s\n", av);
	return ((stat(av, &st) == 0) ? 1 : 0);
}
