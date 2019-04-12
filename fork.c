#include "shell.h"
/**
 * main - fork to execute new processes
 *
 * Return: Always 0.
 */
int _fork(size_t ac, char **av)
{
	size_t i;
	pid_t status, child_pid, my_pid;

	printf("DEBUG: Commands amount: %zu\n", ac);
	for (i = 0; i < ac; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
			return (0);
		my_pid = getpid();
		printf("My pid is %d\n", my_pid);
		if (child_pid)
		{
			printf("DEBUG: Parent Process for shell\n\n");
			wait(&status);
		}
		else
		{
			printf("DEBUG FORK.C: Child Process for %s(%zu)\n\n", av[i], ac);
			//sleep(1);
			if (_stat(av[i]))
			{
				// ToDO: split command and params
				av[0] = "/bin/ls"; /* Test values */
				av[1] =  NULL; 
				_exec(av[i], av);
			}
			else
				return (0);
		}
	}
	return (1);
}
