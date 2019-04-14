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
  ssize_t size = 0;

  (void)size;
  size = getline(&line, &bufsize, stdin);

   return (line);
}

int main(int ac, char **av, char **env)
{
  char *line_returned;
  history_t **history;
  int hist_status = 0;
  char *path;

  history = malloc(sizeof(history_t));
  path = find_path(env);  
  while (1)
  {
    printf("$ ");
    line_returned = _prompt(NULL, NULL);
    ver_buil_comm(line_returned, env);
    _which(path, line_returned);
    hist_status = add_nodeint(history, line_returned);
    if (hist_status < 0)  
      free_listint(*history);
  }
 return (0); 
}
   

