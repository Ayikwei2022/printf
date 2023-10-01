#include "main.h"

/**
 * g_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @lisp: list of arguments.
 *
 * Return: width.
 */
int g_width(const char *format, int *i, va_list lisp)
{
	int cur_i;
	int widt = 0;

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			widt *= 10;
			widt += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			widt = va_arg(lisp, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (widt);
}
