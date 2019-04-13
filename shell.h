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

size_t _prompt(char **, size_t *);
void error_handler(char *, int);
int _fork(size_t, char **);
char *read_line(void);
int _stat(char *);
size_t _strlen(char *str);
int _exec(char *, char *const[]);
size_t _parser_cmd(char *, char **, size_t *);
size_t _parser_arg(char *, char **, size_t *);
void print_char_pointer_arr(char **, size_t);

#endif
