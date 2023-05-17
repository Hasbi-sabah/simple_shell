#include "head.h"
/**
 * is_command - check code
 * @comm: command name
 * Return: command absolute path
 */
char *is_command(const char *comm)
{
	DIR *dir;
	char **cmds = NULL, **path_arr;
	int i = 0, j;
	struct dirent *f;

	path_arr = _strtok(_getenv("PATH"), ":");
	for (j = 0; path_arr[j]; j++)
	{
		dir = opendir(path_arr[j]);
		while ((f = readdir(dir)))
		{
			if (f->d_type == DT_REG)
				i++;
		}
		closedir(dir);
		dir = opendir(path_arr[j]);
		cmds = malloc((i + 1) * sizeof(char *));
		i = 0;
		while ((f = readdir(dir)))
		{
			if (f->d_type == DT_REG)
			{
				cmds[i] = malloc(sizeof(f->d_name));
				_strcpy(cmds[i], f->d_name);
				i++;
			}
		}
		closedir(dir);
		for (i = 0; cmds[i]; i++)
		{
			if (_strcmp(comm, cmds[i]) == 0)
				return (path_arr[j]);
		}
		free(cmds);
	}
	return (NULL);
}
