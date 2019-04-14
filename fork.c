#include "shell.h"
/**
 * _fork - fork code to execute a new command
 * @cmd_node: Command node pointer.
 * @myself: my own name as shell.
 *
 * Return: 1 on sucess, 0 on failure.
 */
int _fork(char *myself, command_t *cmd_node)
{
  pid_t status, child_pid, my_pid;

	child_pid = fork();
	if (child_pid == -1)
		return (0);
	my_pid = getpid();
	if (child_pid)
	{
		wait(&status);
	}
	else
	{
		/* sleep(1); */
		if (_stat(myself, cmd_node->command[0]))
		{
			_exec(cmd_node->command);
		}
		else
			return (0);
	}
	return (1);
}
