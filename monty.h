#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include "list.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>

extern void *data;
extern int err;
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
void swap(stack_t **head, unsigned int line_number);

#endif
