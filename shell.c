#include "shell.h"
/**
 * main - Simple Shell
 * @ac: Argument counter.
 * @av: Argument values.
 * Return: 0 or -1 in failure.
 */

char *read_line(void)
{
  char *line;
  ssize_t bufsize = 0;

  getline(&line, &bufsize, stdin);

   return (line);
}

int main ()
{
  char *line_returned;
  history_t **history;
  int hist_status = 0;
  char *path;

  history = malloc(sizeof(history_t));
  path = find_path();  
  /* printf("::DEBUG:: This is the path  : %s\n", path); */
    /* printf(":DEBUG: Print env\n"); */
    /* Printf env */ 
    /* print_env(); */
  while (1)
  {
    printf("$ ");
    line_returned = read_line();

    /* printf("line %s", line_returned); */
/* Fucntion to verified if the file command exists */
    ver_buil_comm(line_returned);
    

/* Function to find the path of a command */
    _which(path, line_returned);
    /* Add node int history */
    hist_status = add_nodeint(history, line_returned);
    if (hist_status < 0)  
      free_listint(*history);
    /* Print linked list */
    /* printf("Linked list:\n"); */
    /* print_listint(*history); */
    
  }
 return (0); 
}
   

