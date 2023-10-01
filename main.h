#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define LB_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int hnd_print(const char *fmt, int *i,
va_list lisp, char bufer[], int flag_, int widt_, int precisio_, int siz_);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int out_char(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);
int out_string(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);
int out_percent(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);
int out_r(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);

/* Functions to print numbers */
int out_int(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);
int out_binary(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);
int out_unsigned(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);
int out_octal(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);
int out_hexadecimal(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);
int out_hexa_upper(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);

int out_hexa(va_list elems, char mapto[],
char bufer[], int flag_, char flagch, int widt_, int precisio_, int siz_);

/* Function to print non printable characters */
int out_non_printable(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);

/* Funcion to print memory address */
int out_pointer(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);

/* Funciotns to handle other specifiers */
int g_flags(const char *format, int *i);
int g_width(const char *format, int *i, va_list lisp);
int g_precision(const char *format, int *i, va_list lisp);
int g_size(const char *format, int *i);

/*Function to print string in reverse*/
int out_reverse(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);

/*Function to print a string in rot 13*/
int out_rot13string(va_list elems, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);

/* width handler */
int hnd_write_char(char c, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);
int wrt_numb(int is_minus, int ind, char bufer[],
	int flag_, int widt_, int precisio_, int siz_);
int writ_num(int ind, char bufer[], int flag_, int widt_, int precisio_,
	int leng, char pads, char extra_ch);
int wrt_pointer(char bufer[], int ind, int leng,
	int widt_, int flag_, char pads, char extra_c, int pads_start);

int wrt_unsgnd(int is_minus, int ind,
char bufer[],
	int flag_, int widt_, int precisio_, int siz_);

/****************** UTILS ******************/
int _printable(char);
int app_hexa_code(char, char[], int);
int is_digit(char);

long int change_size_number(long int num, int siz_);
long int change_size_unsgnd(unsigned long int num, int siz_);

#endif /* MAIN_H */
