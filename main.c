#include "monty.h"
#define _GNU_SOURCE


bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - program that performs stack operations
 * @argv: array of arguments
 * @argc: number of arguments
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: Can't open file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(agrv[1], "r");
	bus.file = file;

	if (!file)
	{
		fprintf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(&content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
