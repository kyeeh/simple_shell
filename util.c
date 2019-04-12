#include "shell.h"
/**
 * strlen - return the length of a string
 *
 */
size_t _strlen(char *str)
{
	size_t i = 0;

	while(str[i] != '\0')
		i++;
	return (i);
}
