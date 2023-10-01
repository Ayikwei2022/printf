#include "main.h"

/**
 * g_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @lisp: list of arguments.
 *
 * Return: Precision.
 */
int g_precision(const char *format, int *i, va_list lisp)
{
	int cur_i = *i + 1;
	int precisio_ = -1;

	if (format[cur_i] != '.')
		return (precisio_);

	precisio_ = 0;

	for (cur_i += 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			precisio_ *= 10;
			precisio_ += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			precisio_ = va_arg(lisp, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (precisio_);
}
