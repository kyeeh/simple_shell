#include "shell.h"
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int _exec(char **cmd)
{
	//char *cmd[] = {"/bin/ls", "-l", "/usr/", NULL};

	printf("Before execve\n");
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		perror("Error:");
	}
	printf("After execve\n");
	return (0);
}
