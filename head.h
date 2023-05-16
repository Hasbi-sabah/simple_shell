#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <dirent.h>

extern char **environ;
extern int EXIT_STATUS;

char **split_line(char *);
int _getline(char **);
void check_fork_error(char *, char **, char *);
void execmd(char **, char *, char *);
void get_cmds(char ***, char *);
void _free(char **);
void _fork(char *, char **);
int cmd_selector(const char *, char **);
int args_count(char **);
char *is_valid(char *);
char *int_to_str(int, char *);
int args_count(char **);
char *check_ops(char **, char *);
char *_getenv(char *var);
/**
 * struct cmd_executer - structure
 * @cmd: command
 * @exe_func: function
 */
typedef struct cmd_executer
{
	char *cmd;
	int (*exe_func)(int, char **);
} cmd_executer;
int change_dir(int, char **);
int exit_function(int, char **);
int export(int, char **);
int unset(int, char **);
int echo(char **);

/* string functions */
char **_strtok(char *, char *);
char *_strpbrk(char *, char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
char *_strdup(char *);
int _strlen(char *);
int _strcmp(const char *, char *);
char *_strstr(char *, char *);
#endif
