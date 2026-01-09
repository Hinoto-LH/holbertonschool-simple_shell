#include "shell.h"

/**
 * execute_command - executes a command using execve
 * @current_command: array containing the command and its arguments
 * @type_command: type of the command (unused)
 *
 * Description: This function replaces the current process image
 * with a new process image specified by the command. If execve
 * fails, an error message is printed and the process exits.
 *
 * Return: Nothing
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
