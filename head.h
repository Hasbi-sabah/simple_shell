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
int cmd_selector(const char *, char **);
int args_count(char **);
char *is_valid(char *);
char *int_to_str(int, char *);
int args_count(char **);
char *check_ops(char **);
char *_getenv(char *);
int echo(char **);

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
void change_dir(int, char **);
void exit_function(int, char **);
void export(int, char **);
void unset(int, char **);
/* _printf functions */
/**
 * struct conversion - struct
 * @conv_spec: conversion specifier
 * @f: function to be executed
 */
struct conversion
{
	char conv_spec;
	int (*f)(va_list);
};
typedef struct conversion conv_list;
int _printf(const char *format, ...);
int call_funcs(conv_list *conversion,
		va_list conv, const char *format);
int _putchar(char c);
int conv_c(va_list conv);
int conv_s(va_list conv);
int conv_i_d(va_list conv);
/* string functions */
char **_strtok(char *, char *);
char *_strpbrk(char *, char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
char *_strdup(char *);
int _strlen(char *);
int _strcmp(const char *, char *);
int _strncmp(const char *s1, char *s2, int n);
char *_strstr(char *, char *);
char *_memcpy(char *, char *, unsigned int);
int _strrev(char *, int);

#endif
