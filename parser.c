#include "shell.h"
/**
 * _parser - Parse commands from prompt.
 * @cmd_line: command line to be parsed fomr prompt.
 * @sep: separator.
 * @tokens: String array to save tokens
 * @max_tokens: Max tokens allowed.
 */
size_t _parser(char *cmd_line, const char *sep, char **tokens, size_t *max_tokens)
{
	size_t j = 0;


    tokens[j] = strtok(cmd_line, sep); /* get the first token */
    while(tokens[j] != NULL && j < *max_tokens) {/* walk through other tokens */
        tokens[j] == NULL ? j : j++;
        tokens[j] = strtok(NULL, sep);
    }
	return (j); 
}

/**
 * _parser_cmd - Parse commands from prompt.
 * @cmd_line: command line to be parsed fomr prompt.
 * @in_size: command line buffer size.
 * @cmds: String array to storage commands.
 * @out_size: Commands string array (cmds) size.
 */
size_t _parser_cmd(char *cmd_line, char *cmds[], size_t *out_size)
{
	size_t i, j = 0, cmd_sep_num = 1;
	const char *cmd_sep[] = {";","\n"};

	for (i = 0; i < cmd_sep_num; i++)
	{
		cmds[j] = strtok(cmd_line, cmd_sep[i]); /* get the first token */
		while(cmds[j] != NULL && j < *out_size) {/* walk through other tokens */
			cmds[j] == NULL ? j : j++;
			cmds[j] = strtok(NULL, cmd_sep[i]);
		}
	}
	return (j); 
}

/**
 * _parser_arg - Parse arguments for a command.
 * @command: String for a command to parse.
 * @args: String array to save command and arguments.
 * @argc: args size or amount of arguments including command.
 */
size_t _parser_arg(char *command, char **args, size_t *argc)
{
	size_t i, j = 0, cmd_sep_num = 1;
	const char *cmd_sep[] = {" "};

	for (i = 0; i < cmd_sep_num; i++)
	{
		args[j] = strtok(command, cmd_sep[i]); /* get the first token */
		while(args[j] != NULL && j < *argc) {/* walk through other tokens */
			args[j] == NULL ? j : j++;
			args[j] = strtok(NULL, cmd_sep[i]);
		}
	}
	return (j); 
}
