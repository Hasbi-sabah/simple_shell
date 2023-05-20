#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>

extern char **environ;

void split_line(char *, char *);
char **_strtok(char *, char *);
int _getline(char **);
void check_fork_error(char *, char **, char *);
int execmd(char **, char *, char *);
void get_cmds(char ***, char *);
void _free(char **);
int _fork(char *, char **);
int args_count(char **);
char *is_valid(char *);
int args_count(char **);
char *check_ops(char **);
char *_getenv(char *);
int _getalias(char **, char *, int);
int echo(char **);
void error(char *, char **, char *, int);

/* for _printf() */
int to_string(int, unsigned int);
int print_string(int, char *);
/* for cmd exec */

/**
 * struct cmd_executer - structure
 * @cmd: command
 * @exe_func: function
 */
typedef struct cmd_executer
{
	char *cmd;
	int (*exe_func)(int, char **, char *);
} cmd_executer;
int cmd_selector(const char *, char **, char *);
int change_dir(int, char **, char *);
int exit_function(int, char **, char *);
int export(int, char **, char *);
int unset(int, char **, char *);
int env(int, char **, char *);
int alias(int, char **, char *);

/* string functions */
char **_strtok(char *, char *);
char *_strpbrk(char *, char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
char *_strdup(char *);
size_t _strlen(char *);
int _strcmp(const char *, char *);
int _strncmp(const char *, char *, int);
char *_strstr(char *, char *);
char *_memcpy(char *, char *, unsigned int);
int _strrev(char *, int);
void replace_substring(char *, char *, char *);

#endif
