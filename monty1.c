#include "monty.h"
#include "utils.h"

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
		monty_error(line_number, "can't pint, stack empty");
		return;
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
		monty_error(line_number, "can't add, stack too short");
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
		monty_error(line_number, "can't swap, stack too short");
		return;
	}
	temp = first_num->n;
	first_num->n = second_num->n;
	second_num->n = temp;
}
