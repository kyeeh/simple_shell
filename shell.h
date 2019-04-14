#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * struct error_msg - An structure for each error message
 *
 * @ecode: error code
 * @msg: pointer to error message
 * @size: error message length.
 */
typedef struct error_msg
{
	int ecode;
	char *msg;
	int  size;
} error_msg_t;

/**
 * struct cmd - An structure for each command
 *
 * @command: command with arguments.
 * @next: pointer to next command.
 */
typedef struct command_s
{
	char **command;
	struct command_s *next;
} command_t;

/* Shell functions */
command_t **_prompt(char *);
int _fork(char *, command_t *);
int _stat(char *, char *);
int _exec(char **);

/* Utilities */
char *read_line(void);
size_t _strlen(char *str);
command_t *_parser_cmd(char *);
size_t _parser_arg(char *, char **, size_t *);
void print_char_pointer_arr(char **, size_t);

/* Error handler */
void error_handler(char *, int);
void error_handler_set_default(int, char *);

#endif
