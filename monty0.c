#include "monty.h"


/**
 * push_bot - adds a node to the end of the list
 * @head: double pointer to the beginning of the list
 * @n: value to add to new element
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *push_bot(stack_t **head, int n)
{
	return (add_new(head, n));
}

/**
 * pop_top - removes node at the top of the list
 * @head: double pointer to the beginning of the list
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *pop_top(stack_t **head)
{
	stack_t *current;

	if (head == NULL || *head == NULL)
		return (NULL);
	current = *head;

	*head = current->next;
	if (current->next != NULL)
	{
		current->next->prev = NULL;
	}

	return (current);
}

/**
 * pop - removes node at the top of the list
 * @head: double pointer to the beginning of the list
 * @line_number: current line being executed
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *node = pop_top(head);

	if (node == NULL)
	{
		fprintf(stderr, "L %d: can't pop an empty stack\n", line_number);
		data.err = 1;
	}
	free(node);
}

/**
 * push - adds a node to the end of the list
 * @head: double pointer to the beginning of the list
 * @line_number: current line being executed
 */
void push(stack_t **head, unsigned int line_number)
{
	int number = atoi((char *)data.data);

	if (data.data == NULL || number == 0)
	{
		if (!(strlen((char *)data.data) == 1 && ((char *)data.data)[0] == '0'))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			data.err = 1;
		}
	}
	push_bot(head, number);
}

/**
 * pall - prints all the elements of list
 * @head: pointer to the start of the list
 * @line_number: current line being executed
 */
void pall(stack_t **head, unsigned int line_number __attribute__((unused)))
{
	if (*head != NULL)
		print_stack(*head);
}
