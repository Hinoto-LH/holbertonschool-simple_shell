#include "shell.h"

/**
 * builtin_env - prints the current environment
 *
 * Description: This function prints all the environment variables
 * one per line, using the global variable environ.
 *
 * Return: Always 0 (success)
 */
int builtin_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (0);
}
