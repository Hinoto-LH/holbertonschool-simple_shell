#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - looks for files in the PATH
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	char *path, *path_copy, *dir;
	char full_path[1024];
	int i;

	if (ac < 2)
		return (0);

	path = getenv("PATH");
	if (path == NULL)
		return (0);

	path_copy = strdup(path);
	if (path_copy == NULL)
		return (0);

	for (i = 1; i < ac; i++)
	{
		dir = strtok(path_copy, ":");
		while (dir != NULL)
		{
			snprintf(full_path, sizeof(full_path), "%s/%s", dir, av[i]);
			if (access(full_path, X_OK) == 0)
			{
				printf("%s\n", full_path);
				break;
			}
			dir = strtok(NULL, ":");
		}
		strcpy(path_copy, path);
	}

	free(path_copy);
	return (0);
}