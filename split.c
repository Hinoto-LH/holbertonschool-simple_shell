#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
* split_line - splits a line into words
* @line: input line to be split
*
* Description: This function tokenizes the input line using spaces,
* tabs, and newlines as delimiters. It returns a NULL-terminated
* array of strings representing the command and its arguments.
*
* Return: Pointer to an array of strings, or NULL on failure
*/
char **split_line(char *line)
{
	char **argv = malloc(sizeof(char *) * 64);

	char *token;

	int i = 0;

	token = strtok(line, " \t\n");
	while (token)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;
	return (argv);
}
