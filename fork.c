#include "shell.h"
/**
 * main - fork to execute new processes
 *
 * Return: Always 0.
 */
int _fork(char *cmd, char **av)
{
	int status;
	pid_t child_pid, my_pid;

	child_pid = fork();
	if (child_pid == -1)
		return (-1);
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);	
	if (child_pid == 0)
	{
		printf("DEBUG: Child Process for %s\n\n", cmd);
		sleep(1);
	}
	else
	{
		printf("DEBUG: Parent Process for %s\n\n", *av);
		wait(&status);
	}
	return (1);
}
