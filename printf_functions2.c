#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * out_pointer - Prints the value of a pointer variable
 * @elems: List a of arguments
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: get width
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Number of chars printed.
 */
int out_pointer(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	char extra_ch = 0, pads = ' ';
	int id = LB_SIZE - 2, leng = 2, pads_start = 1; /* leng=2, for '0x' */
	unsigned long nub_addrs;
	char mapto[] = "0123456789abcdef";
	void *ads = va_arg(elems, void *);

	UNUSED(widt_);
	UNUSED(siz_);

	if (ads == NULL)
		return (write(1, "(nil)", 5));

	bufer[LB_SIZE - 1] = '\0';
	UNUSED(precisio_);

	nub_addrs = (unsigned long)ads;

	while (nub_addrs > 0)
	{
		bufer[id--] = mapto[nub_addrs % 16];
		nub_addrs /= 16;
		leng++;
	}

	if ((flag_ & F_ZERO) && !(flag_ & F_MINUS))
		pads = '0';
	if (flag_ & F_PLUS)
		extra_ch = '+', leng++;
	else if (flag_ & F_SPACE)
		extra_ch = ' ', leng++;

	id++;

	/*return (write(1, &bufer[i],LB_SIZE - i - 1));*/
	return (wrt_pointer(bufer, id, leng,
		widt_, flag_, pads, extra_ch, pads_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * out_non_printable - Prints ascii codes in hexa of non printable chars
 * @elems: Lista of arguments
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: get width
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Number of chars printed
 */
int out_non_printable(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	int id = 0, offzet = 0;
	char *stg = va_arg(elems, char *);

	UNUSED(flag_);
	UNUSED(widt_);
	UNUSED(precisio_);
	UNUSED(siz_);

	if (stg == NULL)
		return (write(1, "(null)", 6));

	while (stg[id] != '\0')
	{
		if (_printable(stg[id]))
			bufer[id + offzet] = stg[id];
		else
			offzet += app_hexa_code(stg[id], bufer, id + offzet);

		id++;
	}

	bufer[id + offzet] = '\0';

	return (write(1, bufer, id + offzet));
}

/************************* PRINT REVERSE *************************/
/**
 * out_reverse - Prints reverse string.
 * @elems: Lista of arguments
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: get width
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Numbers of chars printed
 */

int out_reverse(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	char *stg;
	int i, cnt = 0;

	UNUSED(bufer);
	UNUSED(flag_);
	UNUSED(widt_);
	UNUSED(siz_);

	stg = va_arg(elems, char *);

	if (stg == NULL)
	{
		UNUSED(precisio_);

		stg = ")Null(";
	}
	for (i = 0; stg[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char ze = stg[i];

		write(1, &ze, 1);
		cnt++;
	}
	return (cnt);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * out_rot13string - Print a string in rot13.
 * @elems: Lista of arguments
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: get width
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Numbers of chars printed
 */
int out_rot13string(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	char x;
	char *stg;
	unsigned int i, j;
	int total = 0;
	char rin[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rout[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	stg = va_arg(elems, char *);
	UNUSED(bufer);
	UNUSED(flag_);
	UNUSED(widt_);
	UNUSED(precisio_);
	UNUSED(siz_);

	if (stg == NULL)
		stg = "(AHYY)";
	for (i = 0; stg[i]; i++)
	{
		for (j = 0; rin[j]; j++)
		{
			if (rin[j] == stg[i])
			{
				x = rout[j];
				write(1, &x, 1);
				total++;
				break;
			}
		}
		if (!rin[j])
		{
			x = stg[i];
			write(1, &x, 1);
			total++;
		}
	}
	return (total);
}
