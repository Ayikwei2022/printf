#include "main.h"

void out_buffer(char bufer[], int *buff_id);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, display = 0, dis_chars = 0;
	int flag_, widt_, precisio_, siz_, buff_id = 0;
	va_list lisp;
	char bufer[LB_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lisp, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			bufer[buff_id++] = format[i];
			if (buff_id == LB_SIZE)
				out_buffer(bufer, &buff_id);
			dis_chars++;
		}
		else
		{
			out_buffer(bufer, &buff_id);
			flag_ = g_flags(format, &i);
			widt_ = g_width(format, &i, lisp);
			precisio_ = g_precision(format, &i, lisp);
			siz_ = g_size(format, &i);
			++i;
			display = hnd_print(format, &i, lisp, bufer,
				flag_, widt_, precisio_, siz_);
			if (display == -1)
				return (-1);
			dis_chars += display;
		}
	}

	out_buffer(bufer, &buff_id);

	va_end(lisp);

	return (dis_chars);
}

/**
 * out_buffer - Prints the contents of the buffer if it exist
 * @bufer: Array of chars
 * @buff_id: Index at which to add next char, represents the length.
 */
void out_buffer(char bufer[], int *buff_id)
{
	if (*buff_id > 0)
		write(1, &bufer[0], *buff_id);

	*buff_id = 0;
}
