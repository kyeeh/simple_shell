#include "shell.h"


char *read_line(void)
{
  size_t linelen;
  size_t buff_size = 1024;
  char line[1024];
  char *lptr = line;

  
  (void)linelen;
  write(STDOUT_FILENO, "$", 1);
  write(STDOUT_FILENO, " ", 1);  
  linelen = getline(&lptr, &buff_size, stdin);
  if (lptr[linelen - 1] == EOF)
    exit (98);
			
  /* while (*line != EOF) */
  /* { */

  /* } */
  return (lptr);
}
