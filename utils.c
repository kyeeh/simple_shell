#include "shell.h"

/**
 * *_strdup - Function that copy an array
 * @str: The string that receives
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *_strdup(char *str)
{
	int i = 0, size = 0;
	char *ar;

	if (!str)
		return (NULL);
	while (str[size])
	size++;
	ar = malloc(size * sizeof(char) + 1);
	if (ar == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	ar[i] = str[i];
	ar[i] = '\0';
	return (ar);
}

/**
 * _strlen - return the length of a string
 * @str: The string that receives.
 * Return: The count of characters in string.
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
 * @values: array of Strings to print.
 * @length: array size.
 */
void print_char_pointer_arr(char *values[], size_t length)
{
	unsigned int i;

	for (i = 0; i < length; i++)
		printf("A[%u]: %s ", i, values[i]);
	printf("\n");
}


/**
 * *add_nodeint - Add node in the begin67ning
 * @head: The pointer of the history list.
 * @head: The pointer of the list.
 *
 * Return: On success 1
 */

int add_nodeint(history_t **head, char *str)
{
	history_t *new = malloc(sizeof(head));
	history_t *copy = *head;

	if (!new)
	{
		free_listint(*head);
		return(-1);
	}

	new->comms = _strdup(str);
	/* printf("DEBUG: Address comms %p\n", (void*)&new->comms);  */
	/*  printf("DEBUG: Address new %p\n", (void*)&new);  */
	/*  printf("DEBUG: Address new next  %p\n", (void*)&new->next);  */
	/*  printf("DEBUG: Address new prev %p\n", (void*)&new->prev);  */
	if (new->comms == NULL)
	{
		free_listint(*head);
		return (-1);
	}
	new->prev = NULL;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
	}
	else
	{
		new->next = copy;
		*head = new;
	}
	return(1);
}

/**
 * free_listint - Print the list of a single list
 * @head: The pointer of the list
 *
 * Return: The number of elements in the list
 */


void free_listint(history_t *head)
{
	history_t *delete;

	if (!head)
		return;
	while (head)
	{
		delete = head->next;
		free(head->comms);
		free(head->prev);
		free(head);
		head = delete;
	}
	free(delete);
}

/**
 * print_listint - Print the list of a single list
 * @h: The pointer of the list
 *
 * Return: The number of elements in the list
 */

void print_listint(const history_t *h)
{
	while (h)
	{
		/* printf("%s", h->comms); */
		h = h->next;
	}
}

/**
 * *string_nconcat - Function that concatenates two strings
 * @s1: The first string that receives
 * @s2: The second string that receives
 * @n: The number of bytes that you need copy
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	int i = 0, j = 0, len_s2 = 0;
	char *ar;

	if (s2 == NULL)
		s2 = "";
	if (s1 == NULL)
		s1 = "";
	len_s2 = _strlen(s2);
	if (n >= (unsigned int)len_s2)
	{
		ar = malloc(_strlen(s1) + len_s2 + 1);
	}
	else
	{
		ar = malloc(_strlen(s1) + n + 1);
	}
	if (ar == NULL)
	{
		return (NULL);
	}
	for (i = 0; s1[i]; i++)
		ar[i] = s1[i];
	if (n >= (unsigned int)len_s2)
	{
		for (j = 0; s2[j]; j++, i++)
		{
			ar[i] = s2[j];
		}
	}
	else
	{
		for (j = 0; (unsigned int)j < n; j++, i++)
			ar[i] = s2[j];
	}
	ar[i] = '\0';
	return (ar);
}

/**
 * *_strcmp - Compare two strings
 * @s1: The string that receives
 * @s2: The second string that receives
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, comparition = 0;

	while (*(s1 + i) && *(s2 + i))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		comparition += s1[i] - s2[i];
		i++;
	}
	return (comparition);
}
