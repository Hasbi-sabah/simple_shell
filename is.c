#include "head.h"

char *is_command(char *comm)
{
	DIR *dir;
	char **cmds = NULL, *path, **path_arr;
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
		i = 0;
		while ((f = readdir(dir)))
		{
			if (f->d_type == DT_REG)
			{
				cmds[i] = malloc(sizeof(f->d_name));
				strcpy(cmds[i], f->d_name);
				i++;
			}
		}
		closedir(dir);
		for (i = 0; cmds[i]; i++)
		{
			if (strcmp(comm, cmds[i]) == 0)
				return (path_arr[j]);
		}
		_free(cmds);
	}
	return (NULL);
}
