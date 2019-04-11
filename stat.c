
#include "shell.h"
/**
 * _stat - stat of a file
 *
 * Return: 1 on sucess, 0 on failure.
 */
int _stat(char *av)
{
	struct stat st;

	printf("DEBUG: Stat for %s\n", av);
	if (stat(av, &st) == 0)
		return (1);
	else
		error_handler(av, 103);
	return (0);
}
