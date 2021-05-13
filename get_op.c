#include "monty.h"

/**
 * get_func - Select the function according to the opcode.
 * @op: operation to get
 * Return: 0 (success).
 */

void (*get_func(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcode_fun[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"nop", nop},
		{"pint", pint},
		{"add", add},
		{"swap", swap},
		{"sub", sub},
		{"mod", mod},
		{"div", divide},
		{"mul", mul},
		{NULL, NULL}
		};

	int pos_op = 0;

	while (opcode_fun[pos_op].opcode)
	{
		if (strcmp(opcode_fun[pos_op].opcode, op) == 0)
		{
			return (opcode_fun[pos_op].f);
		}
		pos_op++;
	}
	return (NULL);
}
