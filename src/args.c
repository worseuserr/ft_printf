#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <stdarg.h>
#include <stdio.h>
#include "internal\common.h"
#define false 0
#define true 1
#define bool int



enum ArgType	typeof(char c)
{

}

bool	is_valid_arg(const char *s, int i)
{
	if (s[i] == '%' && strchr("scpldz", s[i + 1]))
	{
		if (s[i] == 'z' && s[i + 1] != 'u')
			return (false);
		return (s[i + 1]);
	}
	return (false);
}

int	count_args(const char *s)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i++])
		if (is_valid_arg(s, i))
		{
			n++;
			i++;
		}
	return (n);
}

char	*get_arg_types(const char *s, int count)
{
	char	*out;
	char	arg;
	size_t	i;
	size_t	iarg;

	i = 0;
	iarg = 0;
	out = calloc(count, sizeof(char));
	while (s[i])
	{
		arg = is_valid_arg(s, i++);
		if (arg)
		{
			out[iarg++] = arg;
			i++;
		}
	}
	return (out);
}

char	**get_strs(va_list *argv, size_t argn, char *argtypes)
{
	size_t	i;
	char	**out;

	i = 0;
	out = calloc(argn, sizeof(char *));
	if (out == NULL)
		return (NULL);
	while (i < argn)
	{
		parse_arg(out, argv, argtypes, i);
		i++;
	}
	return (out);
}