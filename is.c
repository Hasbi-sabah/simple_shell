#include "head.h"

char *is_command(char *comm)
{
	DIR *dir;
	char **cmds = NULL, *path, **path_arr, *temp;
	int i = 0, j;
	struct dirent *f;

	path = getenv("PATH");
	path_arr = _strtok(path, ":");
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
		if (!cmds)
			exit(0);
		i = 0;
		while ((f = readdir(dir)))
		{
			if (f->d_type == DT_REG)
			{
				cmds[i] = malloc(sizeof(f->d_name));
				if (!cmds[i])
					exit(0);
				strcpy(cmds[i], f->d_name);
				i++;
			}
		}
		closedir(dir);
		for (i = 0; cmds[i]; i++)
		{
			if (strcmp(comm, cmds[i]) == 0)
			{
				temp = path_arr[j];
				_free(cmds);
				_free(path_arr);
				return (temp);
			}
		}
	}
	_free(cmds);
	_free(path_arr);
	if (cmds || path_arr)
		printf("no good\n");
	return (NULL);
}
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
	_free(path_arr);
	return (NULL);
}
void _free(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
