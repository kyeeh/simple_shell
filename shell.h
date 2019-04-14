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

#define BIN_PATH /bin

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
 * @eoc: char to mark the end of command.
 * @command: command with arguments.
 * @next: pointer to next command.
 */
typedef struct command_s
{
	char eoc;
	char **command;
	struct command_s *next;
} command_t;

/* Shell functions */
command_t *_prompt(void);
int _fork(size_t, char **);
int _stat(char *);
int _exec(char *, char *const[]);

/* Utilities */
char *read_line(void);
size_t _strlen(char *str);
command_t *_parser_cmd(char *);
size_t _parser_arg(char *, char **, size_t *);
void print_char_pointer_arr(char **, size_t);

/* Error handler */
void error_handler(int);
void error_handler_set_default(char *);

#endif
