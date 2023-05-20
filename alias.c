#include "head.h"

/**
 * alias - works with aliases
 */
int _alias(int argc, char **args, char *name, aliases *alias, int *idx)
{
	char **al;
	int i, j;

	(void) name;
	if (argc == 1)
	{
		for (i = 0; *idx && i < *idx; i++)
			_printf(1, "%s=%s\n", alias[i].name, alias[i].value);
		return (1);
	}
	for (i = 1; i < argc; i++)
	{
		al = _strtok(args[i], "=");
		j = _getalias(alias, al[0], *idx, 0);
		if (!_strstr(args[i], "="))
		{
			if (j != -1)
				_printf(1, "%s=%s\n", alias[j].name, alias[j].value);
			else
				error(name, args, args[i], 10);
		}
		else if (j != -1)
		{
			alias[j].value = malloc(_strlen(al[1]) + 1 + _strlen("''"));
			_strcpy(alias[j].value, al[1]);
		}
		else
		{
			alias[*idx].name = malloc(_strlen(al[0]) + 1);
			alias[*idx].value = malloc(_strlen(al[1]) + 1 + _strlen("''"));
			_strcpy(alias[*idx].name, al[0]);
			_strcpy(alias[*idx].value, al[1]);
			(*idx)++;
		}
	}
	return (1);
}
