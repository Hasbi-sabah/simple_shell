#include "head.h"

/**
 * conv_c - prints %c
 * @n: n
 * @conv: arg
 * Return: length of write
 */

int conv_c(int n, va_list conv)
{
	char c = va_arg(conv, int);
	int z = 0;

	_putchar(n, c);
	return (z + 1);
}

/**
 * conv_s - prints %s
 * @n: n
 * @conv: arg
 * Return: length of write
 */

int conv_s(int n, va_list conv)
{
	char *p = va_arg(conv, char *), s[] = "(null)";
	int z = 0;

	if (!p)
	{
		for (z = 0; s[z]; z++)
			_putchar(n, s[z]);
		return (z);
	}
	for (z = 0; p[z]; z++)
		_putchar(n, p[z]);
	return (z);
}

/**
 * conv_i_d - prints %i and %d
 * @n: n
 * @conv: arg
 * Return: length of write
 */

int conv_i_d(int n, va_list conv)
{
	int j = va_arg(conv, int), k, flag = 0;
	char temp[25];
	int z = 0;

	if (j < 0)
	{
		j = 0 - j;
		flag = 1;
	}
	if (j == 0)
		flag = 2;
	for (k = 0; j > 0; k++)
	{
		temp[k] = j % 10 + '0';
		j /= 10;
	}
	if (flag == 2)
		temp[k++] = '0';
	if (flag == 1)
		temp[k++] = '-';
	_strrev(temp, k);
	temp[k++] = '\0';
	for (k = 0; temp[k]; k++, z++)
		_putchar(n, temp[k]);
	return (z);
}
