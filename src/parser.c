#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <stdarg.h>
#include <stdio.h>
#include "internal\common.h"
#define false 0
#define true 1
#define bool int

static char	*get_ptrval(void *ptr)
{
    size_t	addr;
    int		num_digits = 16;
    char	*hex_digits;
	char	base[16];

	addr = (size_t)ptr;
	hex_digits = calloc(16, sizeof(char));
	memcpy(base, "0123456789ABCDEF", 16);
    while (num_digits-- - 1 >= 0)
	{
        unsigned int digit = addr & 0xf;
        hex_digits[num_digits] = base[digit];
        addr >>= 4;
    }
	return (hex_digits);
}

static bool	is_lenarg(char *c, const char *pattern)
{
	if (*c == *pattern && *(c + 1) == *(pattern + 1))
		return (true);
	return (false);
}
// if (is_lenarg(&str[i], "hh"))
// 			arg.length = CHAR_INT;
// 		else if (is_lenarg(&str[i], "ll"))
// 			arg.length = LLONG;



//												   *argv -> pass in the va_list in case the width field is dynamic (*)
Arg	parse_arg(const char *str, int *index, va_list *argv)
{
	Arg	arg;

	parse_precision(&arg, str, index, argv);
	parse_width(&arg, str, index, argv);
	parse_length(&arg, str, index);
	parse_type(&arg, str, index);
	return (arg);
}


// void	parse_arg(char **out, va_list *argv, char *argtypes, int i)
// {
// 	// printf("[%p, %s, %d]\n", out, argtypes, i);
// 	// printf("|%c|\n", argtypes[i]);
// 	if (argtypes[i] == 's')
// 		out[i] = strdup(va_arg(*argv, char *));
// 	else if (argtypes[i] == 'd')
// 		out[i] = itoa(va_arg(*argv, int), calloc(sizeof(int), 9), 10);
// 	else if (argtypes[i] == 'l')
// 		out[i] = ltoa(va_arg(*argv, long), calloc(sizeof(long), 9), 10);
// 	else if (argtypes[i] == 'p')
// 		out[i] = get_ptrval(va_arg(*argv, void *));
// 	// printf(":%s:\n", out[i]);
// }
