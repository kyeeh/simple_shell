#include "shell.h"
/**
 * _fork - fork to execute a command
 * @ac: arguments counter
 * @av: arguments array
 * Return: 1 on sucess, 0 on failure.
 */
int _fork(command_t *cmd_node)
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
        printf("DEBUG FORK.C: Child Process for %s\n", cmd_node->command[0]);
        /* sleep(1); */
        if (_stat(cmd_node->command[0]))
        {
            // ToDO: split command and params
            //av[0] = "/bin/ls"; /* Test values */
            //av[ac] =  NULL; 
            _exec(cmd_node->command);
        }
        else
            return (0);
    }
	return (1);
}
