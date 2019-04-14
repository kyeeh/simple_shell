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
	unsigned int j = 0;
    /*const char *cmd_sep[] = {";", "|", "&&", "||"};
	char *cmd_sep = ";|&&";
	char cmd_sep[] = {'"', "'", "`", '\\', '*', "&", "#"}; */

    tokens[j] = strtok(cmd_line, sep); /* get the first token */
    printf( "Token(%u) %s\n", j, tokens[j]);
    while(tokens[j] != NULL && j < *max_tokens) {/* walk through other tokens */
        tokens[j] == NULL ? j : j++;
        tokens[j] = strtok(NULL, sep);
        printf( "Token(%u) %s\n", j, tokens[j]);
    }
	return (j); 
}
/**
 * _parser_cmd - Parses a simple command from prompt.
 * @cmd_line: command line to be parsed from prompt.
 */
command_t *_parser_cmd(char *cmd_line)
{
	unsigned int i = 0;
	char *cmd_str = NULL;
	/* const char *cmd_sep = ";|"; */
	const char *cmd_sep = " ";
	command_t *cmd_node = NULL;

	cmd_str = strtok(cmd_line, cmd_sep); /* get the first token */
	if (cmd_str)
	{
		cmd_node = malloc(sizeof(command_t));
		if (!cmd_node)
			error_handler(104);
		cmd_node->command[i] = cmd_str;
		cmd_node->next = NULL;
		printf( "Token(%u) %s\n", i, cmd_node->command[0]);
		while(cmd_str != NULL) {/* walk through other tokens */
			cmd_str == NULL ? i : i++;
			cmd_str = strtok(NULL, cmd_sep);
			cmd_node->command[i] = cmd_str;
			printf( "Token(%u) %s\n", i, cmd_node->command[i]);
		}
	}
	return (cmd_node); 
}

/**
 * _parser_arg - Parse arguments for a command.
 * @command: String for a command to parse.
 * @args: String array to save command and arguments.
 * @argc: args size or amount of arguments including command.
 */
size_t _parser_arg(char *command, char **args, size_t *argc)
{
	unsigned int i, j = 0, cmd_sep_num = 1;
	const char *cmd_sep[] = {" "};

    printf("DEBUG: Parsing command for argument s: ADDRESS-%p\n", (void *)command);
    printf("DEBUG: Parsing command for arguments: %s\n", command);
	for (i = 0; i < cmd_sep_num; i++)
	{
		args[j] = strtok(command, cmd_sep[i]); /* get the first token */
		printf( "Token(%u) %s\n", j, args[j]);
		while(args[j] != NULL && j < *argc) {/* walk through other tokens */
			args[j] == NULL ? j : j++;
			args[j] = strtok(NULL, cmd_sep[i]);
			printf( "Token(%u) %s\n", j, args[j]);
		}
	}
	return (j); 
}
