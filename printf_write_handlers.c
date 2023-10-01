#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * hnd_write_char - Prints a string
 * @ch: char types.
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags.
 * @widt_: get width.
 * @precisio_: precision specifier
 * @siz_: Size specifier
 *
 * Return: Number of chars printed.
 */
int hnd_write_char(char ch, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char pads = ' ';

	UNUSED(precisio_);
	UNUSED(siz_);

	if (flag_ & F_ZERO)
		pads = '0';

	bufer[i++] = ch;
	bufer[i] = '\0';

	if (widt_ > 1)
	{
		bufer[LB_SIZE - 1] = '\0';
		for (i = 0; i < widt_ - 1; i++)
			bufer[LB_SIZE - i - 2] = pads;

		if (flag_ & F_MINUS)
			return (write(1, &bufer[0], 1) +
					write(1, &bufer[LB_SIZE - i - 1], widt_ - 1));
		else
			return (write(1, &bufer[LB_SIZE - i - 1], widt_ - 1) +
					write(1, &bufer[0], 1));
	}

	return (write(1, &bufer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * wrt_numb - Prints a string
 * @is_minus: Lista of arguments
 * @ind: char types.
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: get width.
 * @precisio_: precision specifier
 * @siz_: Size specifier
 *
 * Return: Number of chars printed.
 */
int wrt_numb(int is_minus, int ind, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	int leng = LB_SIZE - ind - 1;
	char pads = ' ', extra_ch = 0;

	UNUSED(siz_);

	if ((flag_ & F_ZERO) && !(flag_ & F_MINUS))
		pads = '0';
	if (is_minus)
		extra_ch = '-';
	else if (flag_ & F_PLUS)
		extra_ch = '+';
	else if (flag_ & F_SPACE)
		extra_ch = ' ';

	return (writ_num(ind, bufer, flag_, widt_, precisio_,
		leng, pads, extra_ch));
}

/**
 * writ_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @bufer: Buffer
 * @flag_: Flags
 * @widt_: width
 * @prec: Precision specifier
 * @leng: Number length
 * @pads: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int writ_num(int ind, char bufer[],
	int flag_, int widt_, int prec,
	int leng, char pads, char extra_c)
{
	int i, pads_start = 1;

	if (prec == 0 && ind == LB_SIZE - 2 && bufer[ind] == '0' && widt_ == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == LB_SIZE - 2 && bufer[ind] == '0')
		bufer[ind] = pads = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < leng)
		pads = ' ';
	while (prec > leng)
		bufer[--ind] = '0', leng++;
	if (extra_c != 0)
		leng++;
	if (widt_ > leng)
	{
		for (i = 1; i < widt_ - leng + 1; i++)
			bufer[i] = pads;
		bufer[i] = '\0';
		if (flag_ & F_MINUS && pads == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				bufer[--ind] = extra_c;
			return (write(1, &bufer[ind], leng) + write(1, &bufer[1], i - 1));
		}
		else if (!(flag_ & F_MINUS) && pads == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				bufer[--ind] = extra_c;
			return (write(1, &bufer[1], i - 1) + write(1, &bufer[ind], leng));
		}
		else if (!(flag_ & F_MINUS) && pads == '0')/* extra char to left of padd */
		{
			if (extra_c)
				bufer[--pads_start] = extra_c;
			return (write(1, &bufer[pads_start], i - pads_start) +
				write(1, &bufer[ind], leng - (1 - pads_start)));
		}
	}
	if (extra_c)
		bufer[--ind] = extra_c;
	return (write(1, &bufer[ind], leng));
}

/**
 * wrt_unsgnd - Writes an unsigned number
 * @is_minus: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @bufer: Array of chars
 * @flag_: Flags specifiers
 * @widt_: Width specifier
 * @precisio_: Precision specifier
 * @siz_: Size specifier
 *
 * Return: Number of written chars.
 */
int wrt_unsgnd(int is_minus, int ind,
	char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	/* The number is stored at the bufer's right and starts at position i */
	int leng = LB_SIZE - ind - 1, i = 0;
	char pads = ' ';

	UNUSED(is_minus);
	UNUSED(siz_);

	if (precisio_ == 0 && ind == LB_SIZE - 2 && bufer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precisio_ > 0 && precisio_ < leng)
		pads = ' ';

	while (precisio_ > leng)
	{
		bufer[--ind] = '0';
		leng++;
	}

	if ((flag_ & F_ZERO) && !(flag_ & F_MINUS))
		pads = '0';

	if (widt_ > leng)
	{
		for (i = 0; i < widt_ - leng; i++)
			bufer[i] = pads;

		bufer[i] = '\0';

		if (flag_ & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &bufer[ind], leng) + write(1, &bufer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &bufer[0], i) + write(1, &bufer[ind], leng));
		}
	}

	return (write(1, &bufer[ind], leng));
}

/**
 * wrt_pointer - Write a memory address
 * @bufer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @leng: Length of number
 * @widt_: Wwidth specifier
 * @flag_: Flags specifier
 * @pads: Char representing the padding
 * @extra_c: Char representing extra char
 * @pads_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int wrt_pointer(char bufer[], int ind, int leng,
	int widt_, int flag_, char pads, char extra_c, int pads_start)
{
	int i;

	if (widt_ > leng)
	{
		for (i = 3; i < widt_ - leng + 3; i++)
			bufer[i] = pads;
		bufer[i] = '\0';
		if (flag_ & F_MINUS && pads == ' ')/* Asign extra char to left of buffer */
		{
			bufer[--ind] = 'x';
			bufer[--ind] = '0';
			if (extra_c)
				bufer[--ind] = extra_c;
			return (write(1, &bufer[ind], leng) + write(1, &bufer[3], i - 3));
		}
		else if (!(flag_ & F_MINUS) && pads == ' ')/* extra char to left of buffer */
		{
			bufer[--ind] = 'x';
			bufer[--ind] = '0';
			if (extra_c)
				bufer[--ind] = extra_c;
			return (write(1, &bufer[3], i - 3) + write(1, &bufer[ind], leng));
		}
		else if (!(flag_ & F_MINUS) && pads == '0')/* extra char to left of pads */
		{
			if (extra_c)
				bufer[--pads_start] = extra_c;
			bufer[1] = '0';
			bufer[2] = 'x';
			return (write(1, &bufer[pads_start], i - pads_start) +
				write(1, &bufer[ind], leng - (1 - pads_start) - 2));
		}
	}
	bufer[--ind] = 'x';
	bufer[--ind] = '0';
	if (extra_c)
		bufer[--ind] = extra_c;
	return (write(1, &bufer[ind], LB_SIZE - ind - 1));
}
