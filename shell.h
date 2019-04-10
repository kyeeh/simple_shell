#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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

int _prompt(char *, size_t);
void error_handler(char *, int, int );
int _fork(char *, char **);
char *_getline(void);

#endif
