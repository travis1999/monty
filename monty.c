#include <stdio.h>

/**
 * main - entry point of the program
 * @argv: number of arguments
 * @argc: char * array of arguments
 * Return: Always (0) success
 */

int main(int argv, char **argc)
{
	if (argv != 2)
	{
		printf("USAGE: monty file");
		exit(1);
	}
	return (0);
}
