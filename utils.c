#include "utils.h"

/**
 *read_textfile - read text from a file and disp in stdout
 *@filename: name of the file
 *Return: number of letters printed
 */
FILE *open_file(const char *filename)
{
	FILE *fd;

	fd = fopen(filename, "r+");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
