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
 * struct history - An structure for each command readed
 *
 * @h_id: error code
 * @comms: Commands
 * @prev: Previous element
 * @next: Next element
 */

typedef struct history
{
	unsigned int id_h;
	char *comms;
	struct history *prev;
	struct history *next;
} history_t;
/**
 * struct commands - An structure for each command readed
 *
 * @args: Commands
 * @next: Next element
 */

typedef struct commands
{
	char *args;
  struct comm_t *next;
} comm_t;

/* size_t _prompt(char **, size_t *); */
void error_handler(char *, int);
int _fork(size_t, char **);
/* char *read_line(void); */
int _stat(char *);
size_t _strlen(char *str);
int _exec(char *, char *const[]);
size_t _parser_cmd(char *, char **, size_t *);
size_t _parser_arg(char *, char **, size_t *);
void print_char_pointer_arr(char **, size_t);
int add_nodeint(history_t **head, char *str);
  char *_strdup(char *str);
void free_listint(history_t *head);
void print_listint(const history_t *h);

#endif
