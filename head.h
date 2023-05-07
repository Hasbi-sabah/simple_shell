#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void execmd(char **);
char *get_location(char *);
char **_strtok(char *, char *);

#endif
