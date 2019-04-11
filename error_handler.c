#include "shell.h"
/**
 * error_handler - error message printer
 *
 */
void error_handler(char *myself, int size, int msg_code)
{
	int i = 0, ec = 4, printed = 0;

	error_msg_t errors[] = {
		{00, "Error unknown", 14},
		{100, "Error reading from Prompt - Zero tokens", 40},
		{101, "No such file or directory", 26},
		{102, "Error creating child process", 28}
	};

	write(STDERR_FILENO, myself, size);
	write(STDERR_FILENO, ": ", 2);
	for (i = 0; i < ec; i++)
		if (errors[i].ecode == msg_code)
		{
			write(STDERR_FILENO, errors[i].msg, errors[i].size);
			printed = 1;
		}
	if (!printed)
		write(STDERR_FILENO, errors[0].msg, errors[0].size);
	write(STDERR_FILENO, "\n", 1);
}
