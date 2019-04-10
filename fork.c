#include "shell.h"
/**
 * main - fork to execute new processes
 *
 * Return: Always 0.
 */
int _fork(char *file, char **av)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (child_pid == 0)
    {
        printf("DEBUG: Parent Process for %s\n\n", *av);
		sleep(1);
    }
    else
    {
        wait(&status);
        printf("DEBUG: Child Process for %s\n\n", file);
    }
    return (-1);
}
