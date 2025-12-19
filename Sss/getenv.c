#include <stdio.h>

extern char **environ;

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