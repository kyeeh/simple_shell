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

  write(STDOUT_FILENO, "$", 1); 
  write(STDOUT_FILENO, " ", 1);   
  while (1) 
    {

  /* linelen = getline(&lptr, &buff_size, stdin); */
  /* if (lptr[linelen - 1] == EOF) */
  /*   exit (98); */
      inp_char = getchar();

      if (inp_char != 10 || inp_char != EOF)
	{
	  line[linelen] = inp_char;
	  linelen++;
	  
	}
      else
	{
	  line[linelen] = '\0';
	  printf("Llegamos aqui");
	  return (lptr);
	}
}
  return (lptr);
}
