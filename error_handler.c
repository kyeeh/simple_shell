#include "shell.h"
/**
 * error_handler - error message printer
 *
 */
void error_handler(char *myself, int size, int msg_code)
{
	int i = 0, ec = 3;

	error_msg_t errors[] = {
		{00, "Error unknown", 14},
		{100, "Error reading from Prompt - Zero length", 40},
		{101, "No such file or directory", 26}
	};

	write(STDERR_FILENO, myself, size);
	write(STDERR_FILENO, ": ", 2);
	for (i = 0; i < ec; i++)
		if (errors[i].ecode == msg_code)
			write(STDERR_FILENO, errors[i].msg, errors[i].size);
	if (i + 1 == ec)
		write(STDERR_FILENO, errors[0].msg, errors[i].size);
	write(STDERR_FILENO, "\n", 1);
}
