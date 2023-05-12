#include "head.h"

char *is_valid(char *comm)
{
	int i;
	struct stat buf;
	char *path, **path_arr;

	path = getenv("PATH");
	path_arr = _strtok(path, ":");
	path = NULL;
	for (i = 0; path_arr[i]; i++, free(path))
	{
		if (!strstr(comm, "/"))
		{
			path = malloc(strlen(path_arr[i]) + strlen(comm) + 2);
			strcpy(path, path_arr[i]);
			strcat(path, "/");
			strcat(path, comm);
		}
		else
		{
			path = malloc(strlen(comm) + 1);
			strcpy(path, comm);
		}
		if (!access(path, X_OK) && stat(path, &buf) == 0)
		{
			_free(path_arr);
			return (path);
		}

	}
	_free(path_arr);
	return (NULL);
}
