#include "shell.h"

/**
 * initializer - initializes the execution of a command
 * @current_command: array containing the command and its arguments
 * @type_command: type of the command to be executed
 *
 * Description: This function determines how a command should be
 * executed based on its type and prepares it for execution.
 *
 * Return: Nothing
 */
void initializer(char **current_command, int type_command)
{
	pid_t PID;
	int status = 0;

	if (type_command == EXTERNAL_COMMAND || type_command == INTERNAL_COMMAND)
	{
		/* créer un processus */
		PID = fork();

			if (PID == -1)
		{
			perror("fork");
		}

		/* processus enfant */
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
