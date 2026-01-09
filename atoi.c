#include "shell.h"

/**
* _atoi - converts a string to an integer
* @str: string to be converted
*
* Return: the int converted from the string
*/
int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')

		i++;


		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
			{
				sign = -1;
			}
			i++;
		}


	    while (str[i] >= '0' && str[i] <= '9')
	    {
		    result = result * 10 + (str[i] - '0');
		    i++;
	    }

	return (result * sign);
}
