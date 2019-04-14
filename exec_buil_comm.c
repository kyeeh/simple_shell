#include "shell.h"
/**
 * ver_buil_comm - Execute the builtins commands.
 * @str: First arg.
 *
 */

void ver_buil_comm(char *str)
{
  int iterator, result;

  built_t built_func[] =  
     { 
       
       {"env", print_env},
       {"exit", _exit_func},
       {NULL, NULL}
     }; 

  /* printf("Debug %s \n", str); */

  for (iterator = 0; built_func[iterator].command != NULL; iterator++) 
    { 
      result = _strcmp(str, built_func[iterator].command);
      /* printf("result %d, %s, %s\n", result, built_func[iterator].command, str); */
      if (result == 0) 
	{
	  built_func[iterator].f();
	}
    } 

}
