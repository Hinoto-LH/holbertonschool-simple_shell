#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;


#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2


void initializer(char **current_command, int type_command);
void execute_command(char **current_command, int type_command);
char **tokenizer(char *line);
char *_getenv(const char *name);
char *find_in_path(char *cmd);
char **split_line(char *line);
int builtin_env(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
