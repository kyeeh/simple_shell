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

  history = malloc(sizeof(history_t));
  
  while (1)
  {
    printf("$ ");
    line_returned = read_line();
    hist_status = add_nodeint(history, line_returned);
    /* if (hist_status < 0)  */
      free_listint(*history);
    /* Print linked list */
    printf("Linked list:\n");
    print_listint(*history);
    
  }
 return (0); 
}
   

