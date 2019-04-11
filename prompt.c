#include "shell.h"
/**
 * _prompt - prompt actions
 */
size_t _prompt(char *cmd_line, size_t in_size, char **cmds, size_t out_size)
{
	size_t i, j = 0, cmd_sep_num = 1;
	//const char *cmd_sep[] = {";", "|", "&&", "||"};
	const char *cmd_sep[] = {"\n" };
	// char *cmd_sep = ";|&&";
	// char cmd_sep[] = {'"', "'", "`", '\\', '*', "&", "#"};

	write(STDOUT_FILENO, "#cisfun$ ", 9);
	getline(&cmd_line, &in_size, stdin); /* Insert new _getline */
	for (i = 0; i < cmd_sep_num; i++)
	{
		cmds[j] = strtok(cmd_line, cmd_sep[i]); /* get the first token */
		printf( "Token(%zu) %s\n", j, cmds[j]);
		while(cmds[j] != NULL && j < out_size) {/* walk through other tokens */
			cmds[j] == NULL ? j : j++;
			cmds[j] = strtok(NULL, cmd_sep[i]);
			printf( "Token(%zu) %s\n", j, cmds[j]);
			
		}
	}
	return (j); 
}
