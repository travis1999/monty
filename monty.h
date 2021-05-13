#ifndef MONTY_H
#define MONTY_H
#include "list.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct data - stores global variables
 * @data: void pointer used to store any variable
 * @err: error flag
 * Description: stores global variables
 * required for execution
 */
typedef struct data
{
	void *data;
	int err;
} Data;

extern Data data;

stack_t *push_bot(stack_t **head, int n);
stack_t *pop_top(stack_t **head);
void (*get_func(char *op))(stack_t **stack, unsigned int line_number);
void p_error(char *error);
void pop(stack_t **head, unsigned int line_number);
void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void divide(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);

#endif
