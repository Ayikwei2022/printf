#include "main.h"

/**
 * g_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int g_size(const char *format, int *i)
{
	int cur_i = *i + 1;
	int siz_ = 0;

	if (format[cur_i] == 'l')
		siz_ = S_LONG;
	else if (format[cur_i] == 'h')
		siz_ = S_SHORT;

	if (siz_ == 0)
		*i = cur_i - 1;
	else
		*i = cur_i;

	return (siz_);
}
