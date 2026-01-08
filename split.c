#include "shell.h"
#include <stdlib.h>
#include <string.h>

char **split_line(char *line)
{
    char **argv = malloc(sizeof(char *) * 64);
    char *token;
    int i = 0;

    token = strtok(line, " \t\n");
    while (token)
    {
        argv[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    argv[i] = NULL;
    return (argv);
}
