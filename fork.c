#include "shell.h"
/**
 * main - fork to execute new processes
 *
 * Return: Always 0.
 */
int _fork(int ac, char **av)
{
	int i, status;
	pid_t child_pid, my_pid;

	for (i = 0; i < ac; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
			return (0);
		my_pid = getpid();
		printf("My pid is %u\n", my_pid);	
		if (child_pid)
		{
			printf("DEBUG: Parent Process for shell\n\n");
			wait(&status);
		}
		else
		{
			printf("DEBUG: Child Process for %s(%i)\n\n", *av, ac);
			sleep(1);
		}
	}
	return (1);
}
