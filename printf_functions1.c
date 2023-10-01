#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * out_unsigned - Prints an unsigned number
 * @elems: List a of arguments
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: get width
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Number of chars printed.
 */
int out_unsigned(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	int i = LB_SIZE - 2;
	unsigned long int numb = va_arg(elems, unsigned long int);

	numb = change_size_unsgnd(numb, siz_);

	if (numb == 0)
		bufer[i--] = '0';

	bufer[LB_SIZE - 1] = '\0';

	while (numb > 0)
	{
		bufer[i--] = (numb % 10) + '0';
		numb /= 10;
	}

	i++;

	return (wrt_unsgnd(0, i, bufer, flag_, widt_, precisio_, siz_));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * out_octal - Prints an unsigned number in octal notation
 * @elems: Lista of arguments
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: get width
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Number of chars printed
 */
int out_octal(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{

	int i = LB_SIZE - 2;
	unsigned long int numb = va_arg(elems, unsigned long int);
	unsigned long int init_nub = numb;

	UNUSED(widt_);

	numb = change_size_unsgnd(numb, siz_);

	if (numb == 0)
		bufer[i--] = '0';

	bufer[LB_SIZE - 1] = '\0';

	while (numb > 0)
	{
		bufer[i--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flag_ & F_HASH && init_nub != 0)
		bufer[i--] = '0';

	i++;

	return (wrt_unsgnd(0, i, bufer, flag_, widt_, precisio_, siz_));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * out_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @elems: Lista of arguments
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: get width
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Number of chars printed
 */
int out_hexadecimal(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	return (out_hexa(elems, "0123456789abcdef", bufer,
		flag_, 'x', widt_, precisio_, siz_));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * out_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @elems: Lista of arguments
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @widt_: get width
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Number of chars printed
 */
int out_hexa_upper(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_)
{
	return (out_hexa(elems, "0123456789ABCDEF", bufer,
		flag_, 'X', widt_, precisio_, siz_));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * out_hexa - Prints a hexadecimal number in lower or upper
 * @elems: Lista of arguments
 * @mapto: Array of values to map the number to
 * @bufer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @flagch: Calculates active flags
 * @widt_: get width
 * @precisio_: Precision specification
 * @siz_: Size specifier
 * Return: Number of chars printed
 */
int out_hexa(va_list elems, char mapto[], char bufer[],
	int flag_, char flagch, int widt_, int precisio_, int siz_)
{
	int i = LB_SIZE - 2;
	unsigned long int numb = va_arg(elems, unsigned long int);
	unsigned long int init_nub = numb;

	UNUSED(widt_);

	numb = change_size_unsgnd(numb, siz_);

	if (numb == 0)
		bufer[i--] = '0';

	bufer[LB_SIZE - 1] = '\0';

	while (numb > 0)
	{
		bufer[i--] = mapto[numb % 16];
		numb /= 16;
	}

	if (flag_ & F_HASH && init_nub != 0)
	{
		bufer[i--] = flagch;
		bufer[i--] = '0';
	}

	i++;

	return (wrt_unsgnd(0, i, bufer, flag_, widt_, precisio_, siz_));
}
