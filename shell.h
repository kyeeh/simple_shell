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
#define BUFF_SIZE 1024

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
 * struct built_s - Builtings commands
 * @command: command name.
 * @f: function to call.
 * @env: Environment variables.
 *
 * Description: Longer description
 */
typedef struct built_s
{
  char *command;
  void (*f)(char **);
} built_t;

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


/* size_t _prompt(char **, size_t *); */
void error_handler(char *, int);
int _fork(size_t, char **);
/* char *read_line(void); */
int _stat(char *);
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
int add_nodeint(history_t **head, char *str);
  char *_strdup(char *str);
void free_listint(history_t *head);
char *find_path(char **);
char *_strstr(char *haystack, char *needle);
void print_env();
void _which(char *p_rec, char *first_arg);
char *string_nconcat(char *s1, char *s2, unsigned int n);
int _strcmp(char *s1, char *s2);
void _exit_func(); 

/* Error handler */
void error_handler(char *, int);
void error_handler_set_default(int, char *);

#endif
