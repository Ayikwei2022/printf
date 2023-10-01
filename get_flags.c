#include "main.h"

/**
 * g_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int g_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int f, cur_i;
	int flag_ = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		for (f = 0; FLAGS_CH[f] != '\0'; f++)
			if (format[cur_i] == FLAGS_CH[f])
			{
				flag_ |= FLAGS_ARR[f];
				break;
			}

		if (FLAGS_CH[f] == 0)
			break;
	}

	*i = cur_i - 1;

	return (flag_);
}
