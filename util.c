#include "shell.h"
/**
 * error_handler - error message printer
 *
 */

size_t strlen(char *str)
{
	size_t i = 0;

	while(str[i] != '\0')
		i++;
	return (i);
}