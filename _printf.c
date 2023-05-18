#include "head.h"

/**
 * _printf - produces output according to a format
 * @format: what's to be printed
 *
 * Return: int
 */

int _printf(int n, const char *format, ...)
{
	va_list conv;
	conv_list conversion[] = {
		{'c', conv_c},
		{'s', conv_s},
		{'i', conv_i_d},
		{'d', conv_i_d},
		{'\0', NULL}
	};
	int i;

	if (!format)
		return (-1);
	va_start(conv, format);
	i = call_funcs(n, conversion, conv, format);
	va_end(conv);
	_putchar(n, -1);
	return (i);
}
/**
 * call_funcs - calls function for _printf
 * @conversion: struct list
 * @conv: va list
 * @format: what's to be printed
 * Return: int
 */
int call_funcs(int n, conv_list *conversion,
		va_list conv, const char *format)
{
	int i, j, a;

	for (i = 0, j = 0; format[j]; j++)
	{
		if (format[j] == '%')
		{
			for (a = 0; conversion[a].conv_spec; a++)
			{
				if (conversion[a].conv_spec == format[j + 1])
					i += conversion[a].f(n, conv);
			}
			j++;
		}
		else
			i += _putchar(n, format[j]);
	}
	return (i);
}
/**
 * _putchar - prints a character to stdout
 * @c: character to be printed
 * Return: always 1
 */

int _putchar(int n, char c)
{
	static char buff[1024];
	static int idx;

	if (c == -1 || idx >= 1024)
	{
		write(n, buff, idx);
		idx = 0;
	}
	if (c != -1)
		buff[idx++] = c;
	return (1);

}
