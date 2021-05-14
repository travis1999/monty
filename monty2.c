#include "monty.h"
#include "utils.h"

/**
 * sub - subtacts top two elements in the stack stack
 * @head: double pointer to the beginning of the list
 * @line_number: current line being executed
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *num_1 = pop_top(head);

	if (*head == NULL || num_1 == NULL)
	{
		monty_error(line_number, "can't sub, stack too short");
		return;
	}

	(*head)->n = num_1->n - (*head)->n;
	free(num_1);
}

/**
 * divide - divides top two elements in the stack stack
 * @head: double pointer to the beginning of the list
 * @line_number: current line being executed
 */
void divide(stack_t **head, unsigned int line_number)
{
	stack_t *num_1 = pop_top(head);

	if (*head == NULL || num_1 == NULL)
	{
		monty_error(line_number, "can't div, stack too short");
		return;
	}

	(*head)->n = num_1->n * (*head)->n;
	free(num_1);
}

/**
 * mul - subtacts top two elements in the stack stack
 * @head: double pointer to the beginning of the list
 * @line_number: current line being executed
 */
void mul(stack_t **head, unsigned int line_number)
{
	stack_t *num_1 = pop_top(head);

	if (*head == NULL || num_1 == NULL)
	{
		monty_error(line_number, "can't mul, stack too short");
		return;
	}

	(*head)->n = num_1->n * (*head)->n;
	free(num_1);
}

/**
 * mod - mod of top two elements in the stack stack
 * @head: double pointer to the beginning of the list
 * @line_number: current line being executed
 */
void mod(stack_t **head, unsigned int line_number)
{
	stack_t *num_1 = pop_top(head);

	if (*head == NULL || num_1 == NULL)
	{
		monty_error(line_number, "can't mod, stack too short");
		return;
	}

	(*head)->n = num_1->n * (*head)->n;
	free(num_1);
}
