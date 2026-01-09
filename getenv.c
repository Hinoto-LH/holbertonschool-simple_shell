#include "shell.h"

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 *
 * Description: This function searches for an environment variable
 * in the global environ array and returns a pointer to its value.
 * If the variable is not found or name is NULL, NULL is returned.
 *
 * Return: Pointer to the value of the environment variable,
 * or NULL if it does not exist
 */

char *_getenv(const char *name)
{
	int i = 0;
	int j;

	if (name == NULL)
		return (NULL);

	while (environ[i] != NULL)
	{
		j = 0;

		/* comparer name avec le début de environ[i] */
		while (name[j] && environ[i][j] && name[j] == environ[i][j])
			j++;

		/* si name est entièrement parcouru et suivi d'un '=' */
		if (name[j] == '\0' && environ[i][j] == '=')
			return (&environ[i][j + 1]);

		i++;
	}

	return (NULL);
}
