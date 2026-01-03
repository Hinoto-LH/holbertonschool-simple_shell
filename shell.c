#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	pid_t pid;
	int status;
	char *argv[2];

	while (1)
	{
		/* 1. afficher le prompt */
		write(STDOUT_FILENO, "$ ", 2);

		/* 2. lire la commande */
		if (getline(&line, &len, stdin) == -1)
		{
			/* Ctrl + D (EOF) */
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* 3. enlever le '\n' */
		line[strcspn(line, "\n")] = '\0';

		/* 4. si ligne vide, afficher à nouveau le prompt */
		if (line[0] == '\0')
			continue;

		/* 5. créer un processus */
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			continue;
		}

		/* 6. processus enfant */
		if (pid == 0)
		{
			argv[0] = line;
			argv[1] = NULL;

			execve(line, argv, environ);

			/* execve échoue */
			perror("execve");
			exit(1);
		}
		else
		{
			/* 7. processus parent */
			wait(&status);
		}
	}

	free(line);
	return (0);
}
