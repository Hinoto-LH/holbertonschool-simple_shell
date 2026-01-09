#include "shell.h"

/**
 * tokenizer - splits a line into tokens
 * @line: input string to be tokenized
 *
 * Description: This function splits the input line into tokens using
 * spaces and tabs as delimiters. It dynamically allocates memory for
 * the array of tokens and resizes it as needed.
 *
 * Return: Pointer to a NULL-terminated array of strings
 */

char **tokenizer(char *line)
{

	size_t bufsize = 8;
	size_t index = 0;
	char *tok;

	char **args = malloc(bufsize * sizeof(char *));

		if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	tok = strtok(line, " \t");

	while (tok != NULL)
	{
		args[index] = tok;
		index++;

		/*Si on dépasse la taille prévue, on réalloue plus d'espace*/
		if (index >= bufsize)
		{
			bufsize += 8;
			args = realloc(args, bufsize * sizeof(char *));
			if (args == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		tok = strtok(NULL, " \t");
	}

	args[index] = NULL;

	return (args);
}
