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


/**
 * *add_nodeint - Add node in the begin67ning
 * @str: The variable of int type that receives
 * @head: The pointer of the list
 *
 * Return: The number of elements in the list
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
  printf("DEBUG: Address comms %p\n", (void*)&new->comms);
  printf("DEBUG: Address new %p\n", (void*)&new);
  printf("DEBUG: Address new next  %p\n", (void*)&new->next);
  printf("DEBUG: Address new prev %p\n", (void*)&new->prev);
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
      printf("%s", h->comms);
      h = h->next;
    }
}
