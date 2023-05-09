#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
void execmd(char **);
char *get_location(char *);
char **_strtok(char *, char *);
/**
 *struct cmd_executer - Structure
 *@cmd: cmd name
 *@exe_func: execution function
 */
typedef struct
{
	char *cmd;
	void (*exe_func)(va_list);
} cmd_executer;
#endif
