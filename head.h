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
#include <string.h>

extern char **environ;

void split_line(char *, char *);
char **_strtok(char *, char *);
int _getline(char **);
void check_fork_error(char *, char **, char *);
void execmd(char **, char *, char *);
void get_cmds(char ***, char *);
void _free(char **);
void _fork(char *, char **);
int args_count(char **);
char *is_valid(char *);
int args_count(char **);
char *check_ops(char **);
char *_getenv(char *);
int echo(char **);

/* for _printf() */
/**
 * struct conversion - struct
 * @conv_spec: conversion specifier
 * @f: function to be executed
 */
struct conversion
{
	char conv_spec;
	int (*f)(int, va_list);
};
typedef struct conversion conv_list;
int _printf(int n, const char *format, ...);
int call_funcs(int n, conv_list *conversion,
		va_list conv, const char *format);
int _putchar(int n, char c);
int conv_c(int n, va_list conv);
int conv_s(int n, va_list conv);
int conv_i_d(int n, va_list conv);

/* for cmd exec */

/**
 * struct cmd_executer - structure
 * @cmd: command
 * @exe_func: function
 */
typedef struct cmd_executer
{
	char *cmd;
	void (*exe_func)(int, char **);
} cmd_executer;
int cmd_selector(const char *, char **);
void change_dir(int, char **);
void exit_function(int, char **);
void export(int, char **);
void unset(int, char **);
void env(int, char **);

/* string functions */
char **_strtok(char *, char *);
char *_strpbrk(char *, char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
char *_strdup(char *);
int _strlen(char *);
int _strcmp(const char *, char *);
int _strncmp(const char *, char *, int);
char *_strstr(char *, char *);
char *_memcpy(char *, char *, unsigned int);
int _strrev(char *, int);

#endif
