#include "shell.h"
/**
 * error_handler - error message printer
 *
 */
void error_handler(char *myself, int msg_code)
{
	int i = 0, printed = 0;
	size_t size = _strlen(myself);

	error_msg_t errors[] = {
		{00, "Error unknown", 14},
		{100, "Error reading from Prompt - Zero tokens", 40},
		{101, "No such file or directory", 26},
		{102, "Error creating child process", 28},
		{103, "command not found", 17},
		{104, "FATAL ERROR: It's not possible to execute commands, THERE IS NO MEMORY AVAILABLE.", 17},
		{999, "", 0} /* Error Array end condition*/
	};

	write(STDERR_FILENO, myself, size);
	write(STDERR_FILENO, ": ", 2);
	while (errors[i].ecode != 999)
	{
		if (errors[i].ecode == msg_code)
		{
			write(STDERR_FILENO, errors[i].msg, errors[i].size);
			printed = 1;
		}
		i++;
	}
	if (!printed)
		write(STDERR_FILENO, errors[0].msg, errors[0].size);
	write(STDERR_FILENO, "\n", 1);
}

/**
 * error_handler - error message printer
 *
 */
void error_handler_set_default(int ac, char *shell_name)
{
	/* printf("YO SOY: %s\n", shell_name);
	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": ", ac + 1); */
	myself = shell_name;
	/* write(STDERR_FILENO, "\n", 1); */
}
