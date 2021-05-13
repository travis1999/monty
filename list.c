#include "list.h"


/**
 * print_stack - prints all the elements of list
 * @h: pointer to the start of the list
 *
 * Return: number of nodes
 */
size_t print_stack(const stack_t *h)
{
	size_t i;

	for (i = 0; h != NULL; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (i);
}

/**
 * add_new - add a new node at the beginning of the list
 * @head: double pointer to the beginning of the  list
 * @n: value to add to the new element
 * Return: pointer to the new node, or NULL on failure
 */

stack_t *add_new(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	*head = new;

	if (new->next != NULL)
		(new->next)->prev = new;
	return (new);
}

/**
 * add_new_end - adds a node to the end of the list
 * @head: double pointer to the beginning of the list
 * @n: value to add to new element
 * Return: pointer to the new node, or NULL on failure
 */

stack_t *add_new_end(stack_t **head, const int n)
{
	stack_t *new, *tmp;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return (new);
}

/**
 * delete_element - deletes a node at index
 * @head: double pointer to the linked list
 * @index: node index to delete
 * Return: 1 on success, -1 on failure
 */

int delete_element(stack_t **head, unsigned int index)
{
	stack_t *current;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);
	current = *head;
	if (index == 0)
	{
		*head = current->next;
		if (current->next != NULL)
		{
			current->next->prev = NULL;
		}
		free(current);
		return (1);
	}
	for (i = 0; i < index; i++)
	{
		if (current->next == NULL)
			return (-1);
		current = current->next;
	}
	current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
	return (1);
}

/**
 * clean - cleans the stack
 * @h: head of the stack
 */
void clean(stack_t *h)
{
	size_t i;
	stack_t *next = NULL;

	for (i = 0; h != NULL; i++)
	{
		next = h->next;
		free(h);
		h = next;
	}
}
