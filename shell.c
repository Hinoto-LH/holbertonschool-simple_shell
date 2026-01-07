#include "shell.h"

/**
 * 
 * 
 */
int main(void)
{
	size_t len = 0;
	char *line = NULL, *path_cmd;

	while (1)
	{
		/* 1. afficher le prompt */
		if (isatty(STDIN_FILENO))
		{
		write(STDOUT_FILENO, "$ ", 2);
		}

		/* 2. lire la commande */
		if (getline(&line, &len, stdin) == -1)
		{
			/* Ctrl + D (EOF) */
			if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* 3. enlever le '\n' */
		line[strcspn(line, "\n")] = '\0';

		/* 4. si ligne vide, afficher à nouveau le prompt */
		if (line[0] == '\0')
			continue;
		{

		char **argv = tokenizer(line);

		if (argv[0] != NULL) /* Si le nom contient un slash direct */
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
	}
	free(line);
	return (0);
}
