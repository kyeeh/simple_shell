#include "shell.h"
char _getchar()
{
  char c;

  return (read(STDIN_FILENO, &c, 1) == 1) ? (unsigned char) c : EOF;
}

char *read_line(void)
{
  size_t linelen = 0;
  size_t buff_size = 1024;
  char inp_char;
  char line[1024];
  char *lptr = line;

  
  (void)linelen;
  (void)buff_size;
  (void)inp_char;

  write(STDOUT_FILENO, "$", 1); 
  write(STDOUT_FILENO, " ", 1);   
   linelen = getline(&lptr, &buff_size, stdin); 
   if (lptr[linelen - 1] == EOF) 
     exit (98); 
  return (lptr);
}
