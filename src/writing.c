#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <stdarg.h>
#include <stdio.h>
#include "internal\common.h"
#define false 0
#define true 1
#define bool int

bool	write_arg(const char *s, char *str, int i)
{
	if (s[i + 1] == '%')
		write(1, "%", 1);
	else if (is_valid_arg(s, i))
	{
		if (str != NULL) 
			write(1, str, strlen(str));
		return (true);
	}
	return (false);
}

void	write_formatted(const char *s, char **strs)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '%')
			j += write_arg(s, strs[j], i++);
		else if (s[i] == '\%')
			write(1, "%", 1);
		else
			write(1, &s[i], 1);
		i++;
	}
}