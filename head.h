#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <dirent.h>
extern char **environ;
char **split_line(char *);
char **_strtok(char *, char *);
int _getline(char **);
void check_fork_error(char *, char **, char *);
void execmd(char **, char *, char *);
void get_cmds(char ***, char *);
char *is_command(char *);
char *is_path(char *);
void _free(char **);
void exit_function(int, char **);
void _fork(char *, char **);
int cmd_selector(const char *, char **);
int args_count(char **);
void change_dir(int, char **);
typedef struct
{
	char *cmd;
	void (*exe_func)(int, char **);
} cmd_executer;
#endif
