#include "shell.h"

/**
* handle_exit - Gère la commande 'exit' du shell.
* @argv: Tableau de chaînes de caractères (la commande et ses arguments).
* * Return: Retourne 0 pour indiquer au shell de s'arrêter
*/
int handle_exit(char **argv, char *line)
{
	int status = 0;

	if (strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] != NULL)
		{
		status = _atoi(argv[1]);
		}
	}
    free(argv);
    free(line);

	exit(status);
}
