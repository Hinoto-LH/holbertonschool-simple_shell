#include "shell.h"

/**
 * initializer - starts executing everything
 * @current_command: try to check current token
 * @type_command: parse token
 *
 * Return: void function
 */

void initializer(char **current_command, int type_command)
{
	pid_t PID;
	int status = 0;

	if (type_command == EXTERNAL_COMMAND || type_command == INTERNAL_COMMAND)
	{
		PID = fork();
		if (PID == 0)
			execute_command(current_command, type_command);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		execute_command(current_command, type_command);
}
