#include "shell.h"

/**
 * execute_command : execute de la merde
 * current_command
 * type_command
 */
void execute_command(char **current_command, int type_command)
{
	(void)type_command;

	if (execve(current_command[0], current_command, environ) == -1)
	{
		perror(current_command[0]);
		exit(1);
	}
}
