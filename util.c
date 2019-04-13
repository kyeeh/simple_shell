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

/**
 * strlen - return the length of a string
 *
 */
void print_char_pointer_arr(char *values[], size_t length)
{
    size_t i;

    for (i = 0; i < length; i++)
        printf("A[%zu]: %s ", i, values[i]);
    printf("\n");
}
