#include "shell.h"

/**
 * find_in_path - finds a command in the PATH environment variable
 * @cmd: command to search for
 *
 * Description: This function searches for the given command in each
 * directory listed in the PATH environment variable. It builds the
 * full path for the command and checks if it exists and is executable.
 *
 * Return: Pointer to the full path of the executable if found,
 * or NULL if the command is not found or an error occurs
 */
char *find_in_path(char *cmd)
{
	char *path_env, *path_copy, *dir, *full_path;

	size_t len;

	/* 1) récupérer PATH via ta fonction _getenv */
	path_env = _getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	/* 2) faire une copie car strtok modifie la chaîne */
	path_copy = malloc(strlen(path_env) + 1);
	if (path_copy == NULL)
		return (NULL);
	strcpy(path_copy, path_env);

	/* 3) découper path_copy sur ':' */
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		/* 4) construire chemin complet */
		len = strlen(dir) + strlen(cmd) + 2; /* +2 pour '/' et '\0' */
		full_path = malloc(len);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, cmd);

		/* 5) tester s’il est exécutable */
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
