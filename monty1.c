#include "monty.h"

/**
 * nop - wastes cpu cycles
 * @head: double pointer to the beginning of the list
 * @line_number: current line being executed
 */
void nop(stack_t **head __attribute__((unused)),
unsigned int line_number __attribute__((unused)))
{

}
/**
 * pint - prints top in stack
 * @head: double pointer to the beginning of the list
 * @line_number: current line being executed
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L %d: can't pint, stack empty\n", line_number);
		data.err = 1;
	}

	printf("%d\n", (*head)->n);
}

/**
 * add - adds top two elements in the stack stack
 * @head: double pointer to the beginning of the list
 * @line_number: current line being executed
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *num_1 = pop_top(head);

	if (*head == NULL || num_1 == NULL)
	{
		fprintf(stderr, "L %d: can't add, stack too short\n", line_number);
		data.err = 1;
		return;
	}

	(*head)->n = num_1->n + (*head)->n;
	free(num_1);
}

/**
 * swap - swaps top two nodes in the stack
 * @head: double pointer to the beginning of the list
 * @line_number: current line being executed
 */
void swap(stack_t **head, unsigned int line_number)
{
	int temp;
	stack_t *first_num = *head;
	stack_t *second_num = (*head)->next;

	if (first_num == NULL || second_num == NULL)
	{
		fprintf(stderr, "L %d: can't swap, stack too short,\n", line_number);
		data.err = 1;
		return;
	}
	temp = first_num->n;
	first_num->n = second_num->n;
	second_num->n = temp;
}
