#include "main.h"

/**
 * _printable - Evaluates if a char is printable
 * @ch: Char to be evaluated.
 *
 * Return: 1 if ch is printable, 0 otherwise
 */
int _printable(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);

	return (0);
}

/**
 * app_hexa_code - Append ascci in hexadecimal code to buffer
 * @bufer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int app_hexa_code(char ascii_code, char bufer[], int i)
{
	char mapto[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	bufer[i++] = '\\';
	bufer[i++] = 'x';

	bufer[i++] = mapto[ascii_code / 16];
	bufer[i] = mapto[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * change_size_number - Casts a number to the specified size
 * @numb: Number to be casted.
 * @siz_: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int change_size_number(long int numb, int siz_)
{
	if (siz_ == S_LONG)
		return (numb);
	else if (siz_ == S_SHORT)
		return ((short)numb);

	return ((int)numb);
}

/**
 * change_size_unsgnd - Casts a number to the specified size
 * @numb: Number to be casted
 * @siz_: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int change_size_unsgnd(unsigned long int numb, int siz_)
{
	if (siz_ == S_LONG)
		return (numb);
	else if (siz_ == S_SHORT)
		return ((unsigned short)numb);

	return ((unsigned int)numb);
}
