#include "head.h"
/*
void get_cmds(char ***cmds, char *path)
{
	DIR *dir;
	int i = 0;
	struct dirent *f;

	dir = opendir(path);
	while ((f = readdir(dir)))
	{
		if (f->d_type == DT_REG)
			i++;
	}
	closedir(dir);
	dir = opendir(path);
	*cmds = malloc((i + 1) * sizeof(char *));
	i = 0;
	while ((f = readdir(dir)))
	{
		if (f->d_type == DT_REG)
		{
			(*cmds)[i] = malloc(strlen(f->d_name) + 1);
			strcpy((*cmds)[i], f->d_name);
			i++;
		}
	}
	closedir(dir);
}
char *is_command(char *comm, char **path_arr, char **p)
{
	char **cmds = NULL;
	int i = 0, j;

	for (j = 0; path_arr[j]; j++)
	{
		get_cmds(&cmds, path_arr[j]);
		for (i = 0; cmds[i]; i++)
		{
			if (strcmp(comm, cmds[i]) == 0)
			{
				_free(cmds);
				*p = path_arr[j];
				return (path_arr[j]);
			}
		}
		_free(cmds);
	}
	return (NULL);
}
*/


char *is_path(char *comm)
{
	int i;
	char *path, **path_arr;

	path = getenv("PATH");
	path_arr = _strtok(path, ":");
	for (i = 0; path_arr[i]; i++)
	{
		if (strstr(comm, path_arr[i]))
			return (path_arr[i]);
	}
	return (NULL);
}
void _free(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
