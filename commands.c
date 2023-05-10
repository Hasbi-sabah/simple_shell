#include "head.h"

int is_command(const char *comm)
{
	DIR *dir;
	char **cmds = NULL;
	int i = 0;
	struct dirent *f;

	dir = opendir("/bin");
	while ((f = readdir(dir)))
	{
		if (f->d_type == DT_REG)
			i++;
	}
	closedir(dir);
	dir = opendir("/bin");
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
			return (1);
	}
	free(cmds);
	return (0);
}
