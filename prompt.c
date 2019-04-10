#include "shell.h"
/**
 * _prompt - prompt actions
 */
int _prompt(char *line, size_t size)
{

  (void)size;
	write(STDOUT_FILENO, "#cisfun$ ", 9);
    /* return (getline(&line, &size, stdin)); /\* Insert new _getline *\/ */
	line = _getline();
	return (*line); /* Insert new _getline */
}
