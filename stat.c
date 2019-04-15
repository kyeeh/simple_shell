#include "shell.h"
/**
 * _stat - stat of a file.
 * @myself: my own name as shell.
 * @cmd: filename to verify.
 *
 * Return: 1 on sucess, 0 on failure.
 */
int _stat(char *myself, char *cmd)
{
	struct stat st;
	/* char *copy = cmd;
	* int i = 0;
	*
	*while (copy[i])
	*{
	*	printf("char %c [%d] ", copy[i], copy[i]);
	*	i++;
	*} */
	/* printf("DEBUG:STAT: cmd %s \n", cmd); */
	if (stat(cmd, &st) == 0)
		return (1);
	error_handler(myself, 103);
	return (0);
}
