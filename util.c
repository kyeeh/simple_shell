#include "shell.h"
/**
 * strlen - return the length of a string
 *
 */
size_t _strlen(char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * print_char_pointer_arr - print String Array
 *
 */
void print_char_pointer_arr(char *values[], size_t length)
{
	unsigned int i;

	for (i = 0; i < length; i++)
		printf("A[%u]: %s ", i, values[i]);
	printf("\n");
}
