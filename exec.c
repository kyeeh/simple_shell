#include "shell.h"
/**
 * _exec - execve implementation for Simple Shell.
 * @cmd: Command to execute.
 *
 * Return: Always 0.
 */
int _exec(char **cmd)
{

	printf("Before execve\n");
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		perror("Error:");
	}
	printf("After execve\n");
	return (0);
}
