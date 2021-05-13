#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include "utils.h"
#include <stdio.h>
#include "list.h"
#include "string.h"
#include "monty.h"


void *data;
int err;

/**
 * p_error - prints an error to std err
 * @error: error to print
 */

void p_error(char *error)
{
	dprintf(STDERR_FILENO, "%s\n", error);
	exit(EXIT_FAILURE);
}

/**
 * main - entry point of the program
 * @argv: number of arguments
 * @argc: char * array of arguments
 * Return: Always (0) success
 */

int main(int argv, char **argc)
{
	stack_t *program_stack = NULL;
	FILE *fd;
	size_t idx = 0;
	unsigned int line_number = 0;
	char *op, *value, buffer[1024], ch = 'a';
	void (*func)(stack_t **, unsigned int);

	if (argv != 2)
		p_error("USAGE: monty file");
	fd = open_file(argc[1]);
	while (ch != EOF)
	{
		if (err)
			break;
		ch = fgetc(fd);
		if (ch == '\n' || ch == EOF)
		{
			buffer[idx] = '\0';
			idx = 0;
			line_number++;
			op = strtok(buffer, " ");
			value = strtok(NULL, " ");
			if (op == NULL)
				continue;
			func = get_func(op);
			if (func == NULL)
			{
				printf("L%d: unknown instruction %s\n", line_number, op);
				break;
			}
			data = (void *)value;
			func(&program_stack, line_number);
			continue;
		}
		buffer[idx++] = ch;
	}
	fclose(fd);
	clean(program_stack);
	if (err)
		exit(EXIT_FAILURE);
}
