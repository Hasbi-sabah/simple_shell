#include "head.h"

/**
 * exit_function - check code
 * @n: arguments count
 * @args: arguments
 * @name: program name
 * Return: success
 */
int exit_function(int n, char **args, char *name)
{
	int i;

	for (i = 0; n > 1 && args[1][i]; i++)
	{
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			error(name, args, NULL, 2);
			return (0);
		}
	}
	if (n > 1)
		i = atoi(args[1]);
	exit(i);
	return (1);
}
/**
 * change_dir - check code
 * @argc: arguments count
 * @args: arguments
 * @name: program name
 * Return: success
 */
int change_dir(int argc, char **args, char *name)
{
	char *path;
	static char *previous;

	if (!previous)
		getcwd(previous, 1024);
	path = argc == 1 || _strcmp(args[1], "~") == 0 ? _getenv("HOME") : args[1];
	if (_strcmp(path, "-") == 0)
		path = previous;
	if (chdir(path) < 0)
	{
		error(name, args, path, 3);
		return (0);
	}
	getcwd(previous, 1024);
	setenv("PWD", path, 1);
	if (argc == 1)
	{
		print_string(path);
		write(1, "\n", 1);
	}
	return (1);
}
/**
 * export - check code
 * @argc: arguments count
 * @args: arguments
 * @name: program name
 * Return: success
 */
int export(int argc, char **args, char *name)
{
	int i = 0;
	char *temp;

	if (argc != 3)
	{
		error(name, args, NULL, 4);
		return (0);
	}
	else
	{
		temp = _getenv(args[1]);
		if (temp)
		{
			_strcpy(temp, args[2]);
			_strcat(temp, temp + _strlen(args[2]));
		}
		else
		{
			while (environ[i])
				i++;
			environ[i] = malloc(_strlen(args[1]) + _strlen(args[2]) + 3);
			_strcat(environ[i], args[1]);
			_strcat(environ[i], "=");
			_strcat(environ[i], args[2]);
			environ[++i] = NULL;
		}
		return (1);
	}
}
/**
 * unset - check code
 * @argc: arguments count
 * @args: arguments
 * @name: program name
 * Return: success
 */
int unset(int argc, char **args, char *name)
{
	int i;

	if (argc != 2)
	{
		error(name, args, NULL, 5);
		return (0);
	}
	else if (_getenv(args[1]) == NULL)
	{
		error(name, args, NULL, 6);
		return (0);
	}
	else
	{
		for (i = 0; environ[i]; i++)
		{
			if (_strncmp(environ[i], args[1], _strlen(args[1])) == 0)
			{
				environ[i] = NULL;
				break;
			}
		}
		return (1);
	}
}
/**
 * env - prints env
 * @argc: argc
 * @args: arguments
 * @name: program name
 * Return: success
 */
int env(int argc, char **args, char *name)
{
	char *env;

	(void) argc;
	(void) args;
	(void) name;
	for (env = environ; *env; env++)
	{
		print_string(*env);
		write(1, "\n", 1);
	}
	return (1);
}
/**
 * alias - works with aliases
 * @argc: argc
 * @args: arguments
 * @name: name file
 */
int alias(int argc, char **args, char *name)
{
	static char **aliases;
	char **alias;
	static int idx;
	int i, j;

	(void) name;
	if (argc == 1)
	{
		for (i = 0; idx && i < idx; i++)
		{
			print_string(aliases[i]);
			write(1, "\n", 1);
		}
		return (1);
	}
	for (i = 1; i < argc; i++)
	{
		alias = _strtok(args[i], "=");
		j = _getalias(aliases, alias[0], idx);
		if (!_strstr(args[i], "="))
		{
			if (j != -1)
			{
				print_string(aliases[j]);
				write(1, "\n", 1);
			}
			else
				error(name, args, args[i], 10);
		}
		else if (j != -1)
		{
			aliases[j] = NULL;
			aliases[j] = malloc(_strlen(args[i]) + 1 + _strlen("''"));
			_strcpy(aliases[j], args[i]);
		}
		else
		{
			if (!idx)
				aliases = malloc(sizeof(char *));
			aliases[idx] = malloc(_strlen(args[i]) + 1 + _strlen("''"));
			_strcpy(aliases[idx], args[i]);
			idx++;
		}
	}
	return (1);
}
