#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	pid_t pid;
	int status;
	char *argv[] = {NULL, NULL};

	while (1)
	{
		/* 1. afficher le prompt */
		write(STDOUT_FILENO, "$ ", 2);

		/* 2. lire la commande */
		if (getline(&line, &len, stdin) == -1)
			break;

		/* enlever le '\n' */
		line[strcspn(line, "\n")] = '\0';

		/* si l'utilisateur tape juste Entrée */
		if (line[0] == '\0')
			continue;

		/* 3. créer un processus */
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			continue;
		}

		/* 4. processus enfant */
		if (pid == 0)
		{
			argv[0] = line;
			execve(line, argv, NULL);

			/* execve échoue */
			perror("execve");
			exit(1);
		}
		else
		{
			/* 5. processus parent */
			wait(&status);
		}
	}

	free(line);
	return (0);
}