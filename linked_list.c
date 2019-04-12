#include "shell.h"
/**
 * *add_nodeint_end - Print the list of a single list
 * @n: The variable of int type that receives
 * @head: The pointer of the list
 *
 * Return: The number of elements in the list
 */


void *add_nodeint_end(history_t **head, char *string)
{
  history_t *new = malloc(sizeof(head));
  history_t *copy = *head;
  unsigned int hist_id= 1;

  if (!new)
    return (NULL);
  new->str = _strdup(string);
  new->next = NULL;
  if (!*head)
    {
      *head = new;
      return (*head);
    }
  while (copy->next)
    {
      hist_id++;
      new->h_id = hist_id;
      printf("%d %s", copy->h_id,copy->str);
      copy = copy->next;
    }
  copy->next = new;
}
