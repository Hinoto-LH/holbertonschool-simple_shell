#include <stdio.h>

/* environ est fourni par le runtime C (POSIX) */
extern char **environ;

int main(int argc, char *argv[], char *envp[])
{
    printf("Adresse de envp     : %p\n", (void *)envp);
    printf("Adresse de environ  : %p\n", (void *)environ);

    return 0;
}