#include "shell.h"

/**
 * 
 * 
 */
int main(void)
{
	size_t len = 0;
	char *line = NULL, *path_cmd, **argv;

	while (1)
	{
		if (isatty(STDIN_FILENO)) /* 1. afficher le prompt */
			write(STDOUT_FILENO, "$ ", 2);

		if (getline(&line, &len, stdin) == -1) /* 2. lire la commande */
		{
			if (isatty(STDIN_FILENO)) /* Ctrl + D (EOF) */
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		line[strcspn(line, "\n")] = '\0'; /* 3. enlever le '\n' */

		if (line[0] == '\0') /* 4. si ligne vide, afficher à nouveau le prompt */
			continue;

		argv = tokenizer(line);

		if (argv[0] != NULL)
		{
			if (strchr(argv[0], '/') != NULL)
				path_cmd = strdup(argv[0]); /* chemin donné directement*/
			else
				path_cmd = find_in_path(argv[0]);

			if (path_cmd != NULL)
			{
				argv[0] = path_cmd;
				initializer(argv, EXTERNAL_COMMAND);
				free(path_cmd);
			}
		}
		free(argv);
	}
	free(line);
	return (0);
}
