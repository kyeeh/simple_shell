
#include "shell.h"
/**
 * _stat - stat of a file
 *
 * Return: 1 on sucess, 0 on failure.
 */
int _stat(char *cmd)
{
	struct stat st;

	printf("DEBUG: Stat for %s\n", cmd);
	if (stat(cmd, &st) == 0)
		return (1);
	else
		error_handler(cmd, 103);
	return (0);
}
