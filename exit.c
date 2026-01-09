#include "shell.h"

/**
 * handle_exit - handles the exit built-in command
 * @argv: array containing the command and its arguments
 * @line: input line to be freed before exiting
 *
 * Description: This function checks if the command is "exit".
 * If an exit status is provided, it is converted to an integer.
 * The function frees allocated resources and terminates the shell
 * with the specified status.
 *
 * Return: Nothing
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
