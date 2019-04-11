#include "shell.h"
/**
 * _prompt - prompt actions
 */
int _prompt(char *cmd_line, size_t in_size, char **cmds, size_t out_size)
{
	int i, j = 0, cmd_sep_num = 3;
	const char cmd_sep[] = {";", "|", "&&"};
	// char *cmd_sep = ";|&&";
	// char cmd_sep[] = {'"', "'", "`", '\\', '*', "&", "#"};

	write(STDOUT_FILENO, "#cisfun$ ", 9);
	getline(&cmd_line, &in_size, stdin); /* Insert new _getline */
	for (i = 0; i < cmd_sep_num; i++)
	{
		while(cmds[j] != NULL && j < out_size) {
			cmds[j] = strtok(cmd_line, cmd_sep[i]);
			printf( "Token(j) %s\n", j, *cmds[j]);
			j++;
		}
	}
	return (j); 
}
