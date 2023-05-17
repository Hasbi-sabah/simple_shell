#include "head.h"

/**
 * conv_c - prints %c
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_c(va_list conv)
{
	char c = va_arg(conv, int);
	int z = 0;

	_putchar(c);
	return (z + 1);
}

/**
 * conv_s - prints %s
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_s(va_list conv)
{
	char *p = va_arg(conv, char *), s[] = "(null)";
	int z = 0;

	if (!p)
	{
		for (z = 0; s[z]; z++)
			_putchar(s[z]);
		return (z);
	}
	for (z = 0; p[z]; z++)
		_putchar(p[z]);
	return (z);
}

/**
 * conv_i_d - prints %i and %d
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_i_d(va_list conv)
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
	for (k = 0; temp[k]; k++, z++)
		_putchar(temp[k]);
	return (z);
}
