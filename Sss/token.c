#include <string.h>
#include <stdio.h>

int main ()
{
	char myStr[] = "Valentin est un noob";

	char * myPtr = strtok(myStr, " ");

	while (myPtr != NULL)
	{
		printf("%s\n", myPtr);
		myPtr = strtok(NULL, " ");
	}
	return (0);
}
