#include "shell.h"
/**
 * _exec - execve implementation for Simple Shell.
 * @cmd: Command to execute.
 *
 * Return: Always 0.
 */
int _exec(char **cmd)
{

	if (execve(cmd[0], cmd, NULL) == -1)
	{
		perror("Error:");
	}
	return (0);
}
