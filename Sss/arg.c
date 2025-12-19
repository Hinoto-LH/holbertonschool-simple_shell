#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
    for (i = 1; i < 4; i++)
    {
        printf("%s\n", av[i]);
    }

	return (0);
}



/* ./a.out mon simple shell */
/* [[a.out], [mon], [simple], [shell]]*/