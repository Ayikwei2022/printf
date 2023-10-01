#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * out_char - Prints a char
 * @elems: List a of arguments
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: Width
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Number of chars printed
 */
int out_char(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	char ch = va_arg(elems, int);

	return (hnd_write_char(ch, bufer, flag_, widt_, precisio_, siz_));
}
/************************* PRINT A STRING *************************/
/**
 * out_string - Prints a string
 * @elems: List a of arguments
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: get width.
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Number of chars printed
 */
int out_string(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	int lent = 0, i;
	char *stg  = va_arg(elems, char *);

	UNUSED(bufer);
	UNUSED(flag_);
	UNUSED(widt_);
	UNUSED(precisio_);
	UNUSED(siz_);
	if (stg == NULL)
	{
		stg = "(null)";
		if (precisio_ >= 6)
			stg = "      ";
	}

	while (stg[lent] != '\0')
		lent++;

	if (precisio_ >= 0 && precisio_ < lent)
		lent = precisio_;

	if (widt_ > lent)
	{
		if (flag_ & F_MINUS)
		{
			write(1, &stg[0], lent);
			for (i = widt_ - lent; i > 0; i--)
				write(1, " ", 1);
			return (widt_);
		}
		else
		{
			for (i = widt_ - lent; i > 0; i--)
				write(1, " ", 1);
			write(1, &stg[0], lent);
			return (widt_);
		}
	}

	return (write(1, stg, lent));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * out_percent - Prints a percent sign
 * @elems: Lista of arguments
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: get width.
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Number of chars printed
 */
int out_percent(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	UNUSED(elems);
	UNUSED(bufer);
	UNUSED(flag_);
	UNUSED(widt_);
	UNUSED(precisio_);
	UNUSED(siz_);
	return (write(1, "%%", 1));
}

/************************ PRINT INT *************************/
/**
 * out_int - Print int
 * @elems: Lista of arguments
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: get width.
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Number of chars printed
 */
int out_int(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	int i = LB_SIZE - 2;
	int is_minus = 0;
	long int n = va_arg(elems, long int);
	unsigned long int numb;

	n = change_size_number(n, siz_);

	if (n == 0)
		bufer[i--] = '0';

	bufer[LB_SIZE - 1] = '\0';
	numb = (unsigned long int)n;

	if (n < 0)
	{
		numb = (unsigned long int)((-1) * n);
		is_minus = 1;
	}

	while (numb > 0)
	{
		bufer[i--] = (numb % 10) + '0';
		numb /= 10;
	}

	i++;

	return (wrt_numb(is_minus, i, bufer, flag_, widt_, precisio_, siz_));
}

/************************* PRINT BINARY *************************/
/**
 * out_binary - Prints an unsigned number
 * @elems: Lista of arguments
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: get width.
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Numbers of char printed.
 */
int out_binary(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	unsigned int n, m, i, add;
	unsigned int ab[32];
	int enlist;

	UNUSED(bufer);
	UNUSED(flag_);
	UNUSED(widt_);
	UNUSED(precisio_);
	UNUSED(siz_);

	n = va_arg(elems, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	ab[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		ab[i] = (n / m) % 2;
	}
	for (i = 0, add = 0, enlist = 0; i < 32; i++)
	{
		add += ab[i];
		if (add || i == 31)
		{
			char z = '0' + ab[i];

			write(1, &z, 1);
			enlist++;
		}
	}
	return (enlist);
}
