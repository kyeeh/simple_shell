#include "shell.h"

int _getchar(void)
{
  return (0);
}

char *read_line(void)
{
  static size_t buff_size = 1024;
  static char inp_char;
  static char line[1024];
  static char *lptr;
  static int pos = 0;

  (void)lptr;  
  (void)buff_size;

  write(STDOUT_FILENO, "$", 1); 
  write(STDOUT_FILENO, " ", 1);   
  while(1)
    {
      inp_char = getchar();/*provisional getchar function*/

    if (inp_char == '\n')
      {
	line[pos] = '\0';
	lptr = line;
	return (lptr);
      }
    else
      {
	line[pos] = inp_char;
      }
    pos++;
    }
}
