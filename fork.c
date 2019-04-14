#include "shell.h"
/**
 * _fork - fork to execute a command
 * @ac: arguments counter
 * @av: arguments array
 * Return: 1 on sucess, 0 on failure.
 */
int _fork(size_t ac, char **av)
{
  pid_t status, child_pid, my_pid;

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
        if (_stat(*av))
        {
            av[ac] =  NULL; 
            _exec(av[0], av);
        }
        else
            return (0);
    }
	return (1);
}
