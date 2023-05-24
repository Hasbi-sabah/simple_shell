#include "head.h"

/**
 * check_alias - check code
 * @arr: arguments
 * @alias: alias array
 * @idx: integer
 * Return: none
 */
void check_alias(char ***arr, aliases *alias, int idx)
{
	int i, n;

	for (i = 0; (*arr)[i]; i++)
	{
		n = _getalias(alias, (*arr)[i], idx);
		if (n != -1)
		{
			(*arr)[i] = NULL;
			(*arr)[i] = malloc(_strlen(alias[n].value) + 1);
			_strcpy((*arr)[i], alias[n].value);
		}
	}
}
/**
 * and_handling - check code
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 * Return: integer
 */
int and_handling(char *line, char *name, aliases *alias, int *idx)
{
	char **arr, **line_split;
	int break_condition, argc, selector, i = 0;

	line_split = _strtok(line, "&\n");
	while (line_split[i])
	{
		arr = _strtok(line_split[i], " \t");
		if (args_count(arr) == 0)
		{
			_free(arr);
			_free(line_split);
			return (error(name, NULL, NULL, 7));
		}
		i++;
	}
	i = 0;
	while (line_split[i])
	{
		break_condition = 0;
		arr = _strtok(line_split[i], " \t");
		if (_strcmp(arr[0], "alias"))
			check_alias(&arr, alias, *idx);
		argc = args_count(arr);
		selector = cmd_selector(arr[0], arr, name, alias, idx);
		if (argc > 0 && selector < 0)
			break_condition = 1 - _fork(name, arr);
		else if (argc > 0)
			break_condition = 1 - selector;
		_free(arr);
		if (break_condition)
		{
			_free(line_split);
			return (0);
		}
		i++;
	}
	_free(line_split);
	return (EXIT_FAILURE);
}
/**
 * or_handling - check code
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 * Return: integer
 */
int or_handling(char *line, char *name, aliases *alias, int *idx)
{
	char **arr, **line_split;
	int break_condition, argc, selector, i = 0;

	line_split = _strtok(line, "|\n");
	while (line_split[i])
	{
		arr = _strtok(line_split[i], " \t");
		if (args_count(arr) == 0)
		{
			_free(arr);
			_free(line_split);
			return (error(name, NULL, NULL, 8));
		}
		i++;
	}
	i = 0;
	while (line_split[i])
	{
		arr = _strtok(line_split[i], " \t");
		if (_strcmp(arr[0], "alias"))
			check_alias(&arr, alias, *idx);
		break_condition = 0;
		argc = args_count(arr);
		selector = cmd_selector(arr[0], arr, name, alias, idx);
		if (argc > 0 && selector < 0)
			break_condition = _fork(name, arr);
		else if (argc > 0)
			break_condition = selector;
		_free(arr);
		if (break_condition)
		{
			_free(line_split);
			return (0);
		}
		i++;
	}
	_free(line_split);
	return (EXIT_FAILURE);
}
/**
 * semi_column_handling - check code
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 * Return: integer
 */
int semi_column_handling(char *line, char *name, aliases *alias, int *idx)
{
	char **arr, **line_split;
	int argc, i = 0;

	line_split = _strtok(line, ";\n");
	while (line_split[i])
	{
		arr = _strtok(line_split[i], " \t");
		if (args_count(arr) == 0)
		{
			_free(arr);
			_free(line_split);
			return (error(name, NULL, NULL, 9));
		}
		i++;
	}
	i = 0;
	while (line_split[i])
	{
		arr = _strtok(line_split[i], " \t");
		if (_strcmp(arr[0], "alias"))
			check_alias(&arr, alias, *idx);
		argc = args_count(arr);
		if (argc > 0 && cmd_selector(arr[0], arr, name, alias, idx) < 0)
		{
			if (!_fork(name, arr))
			{
				_free(arr);
				_free(line_split);
				return (EXIT_FAILURE);
			}
		}
		else if (argc == 0)
		{
			_free(arr);
			_free(line_split);
			return (error(name, NULL, NULL, 9));
		}
		_free(arr);
		i++;
	}
	_free(line_split);
	return (0);
}
/**
 * split_line - read command line
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 * Return: integer
 */
int split_line(char *line, char *name, aliases *alias, int *idx)
{
	size_t old_len = _strlen(line);
	size_t new_len;
	char *temp;

	temp = _strstr(line, "#");
	if (temp)
		*temp = '\0';
	replace_substring(line, "&&", "&");
	new_len = _strlen(line);
	if (new_len < old_len)
	{
		replace_substring(line, "&&", "&");
		if (_strlen(line) < new_len)
			return (error(name, NULL, NULL, 7));
		return (and_handling(line, name, alias, idx));
	}
	replace_substring(line, "||", "|");
	new_len = _strlen(line);
	if (new_len < old_len)
	{
		replace_substring(line, "||", "|");
		if (_strlen(line) < new_len)
			return (error(name, NULL, NULL, 8));
		return (or_handling(line, name, alias, idx));
	}
	if (_strstr(line, ";;"))
		return (error(name, NULL, NULL, 9));
	replace_substring(line, "\n", ";");
	return (semi_column_handling(line, name, alias, idx));
}
