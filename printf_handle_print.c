#include "main.h"
/**
 * hnd_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @lisp: List of arguments to be printed.
 * @ind: ind.
 * @bufer: Buffer array to handle print.
 * @flag_: Calculates active flags
 * @widt_: get width.
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: 1 or 2;
 */
int hnd_print(const char *fmt, int *ind, va_list lisp, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	int i, unk_len = 0, dis_chars = -1;
	fmt_t fmt_elems[] = {
		{'c', out_char}, {'s', out_string}, {'%', out_percent},
		{'i', out_int}, {'d', out_int}, {'b', out_binary},
		{'u', out_unsigned}, {'o', out_octal}, {'x', out_hexadecimal},
		{'X', out_hexa_upper}, {'p', out_pointer}, {'S', out_non_printable},
		{'r', out_reverse}, {'R', out_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_elems[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_elems[i].fmt)
			return (fmt_elems[i].fn(lisp, bufer, flag_, widt_, precisio_, siz_));

	if (fmt_elems[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unk_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unk_len += write(1, " ", 1);
		else if (widt_)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unk_len += write(1, &fmt[*ind], 1);
		return (unk_len);
	}
	return (dis_chars);
}

