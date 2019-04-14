#include "shell.h"
/**
 * main - Simple Shell
 * @ac: Argument counter.
 * @av: Argument values.
 * Return: 0 or -1 in failure.
 */

char *read_line(void)
{

	char *shell_pharse;
	command_t **cmd_list = NULL; /* Command List */

	shell_pharse = isatty(STDIN_FILENO) ? "#cisfun$ " : NULL;
	while (1)
	{
		cmd_list = _prompt(shell_pharse); /* get commands from cmd_line */
		if (cmd_list)
		{
			if (!_fork(av[0], *cmd_list))
				error_handler(av[0], 102);
		}
		else
			error_handler(av[0], 103);
	}
	return (0);
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
   

