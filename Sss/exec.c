#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    for (i = 0; i <= 4; i++)
    {
        pid = fork();
        
        if (pid != 0)
        {
            return (-1);
        }

        if (pid == 0)
        {
            char *argv[] = {"/bin/ls", "-l",, NULL};
        }
    }
}