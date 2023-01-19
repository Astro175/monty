#include "main.h"
#define _GNU_SOURCE

/**
 * main - program that performs stack operations
 * @argv: array of arguments
 * @argc: number of arguments
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	char *token;
	ssize_t read;
	unsigned int line_number = 0;
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		line_number++;
		token = strtok(line, " \n");
		if (token == NULL)
			continue;
		while (ops[i].opcode != NULL)
		{
			if (strcmp(token, ops[i].opcode) == 0)
			{
				ops[i].f(&head, line_number);
				break;
			}
			i++;
		}
		if (ops[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
