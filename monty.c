#include "utils.h"
#include <stdio.h>
#include "list.h"


/**
 * main - entry point of the program
 * @argv: number of arguments
 * @argc: char * array of arguments
 * Return: Always (0) success
 */

int main(int argv, char **argc)
{
	stack_t *program_stack = malloc(sizeof(program_stack)); 
	FILE *fd;
	char buffer[1024];
	char ch = 'a';
	size_t idx = 0;
	size_t line_number = 0;

	char *op;
	char *value;

	if (argv != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open_file(argc[1]);

	while (ch != EOF)
	{
		ch = fgetc(fd);
		if (ch == '\n')
		{
			buffer[idx] = '\0';
			idx = 0;
			
			line_number++;

			op = strtok(buffer, " ");
			value = strtok(NULL, " ");

			printf("Line: %ld, {%s, %s}\n", line_number, op, value);
			continue;
		}

		buffer[idx] = ch;
		idx++;

	}
	
	fclose(fd);
	free(program_stack);
	return (0);
}
