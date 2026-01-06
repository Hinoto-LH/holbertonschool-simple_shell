#include "shell.h"

/*
* tokenizer: découpe une ligne en mots, c'est moi qui te découpe si tu passes pas la Betty
* @line : la ligne à analyser
* return un tableau de chaînes avec les tokens, terminé par NULL
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
