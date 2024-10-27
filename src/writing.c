#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <stdarg.h>
#include <stdio.h>
#include "internal\common.h"
#define false 0
#define true 1
#define bool int

size_t	chrcount(const char *str, int c)
{
	size_t	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

bool	write_arg(Arg arg, va_list *argv)
{

}

void	write_formatted(const char *str, va_list *argv)
{
	// Arg		*args;
	size_t	i;

	i = 0;
	// args = (Arg *)malloc(sizeof(Arg) * chrcount(str, '%'));
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				write(1, &str[i++], 1);
			write_arg(parse_arg(str, &i, &argv), &argv);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}


// size_t	j;
// 	size_t	i;

// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '%')
// 			j += write_arg(s, strs[j], i++);
// 		else if (s[i] == '\%')
// 			write(1, "%", 1);
// 		else
// 			write(1, &s[i], 1);
// 		i++;
// 	}
