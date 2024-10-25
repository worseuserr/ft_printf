#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <stdarg.h>
#define false 0
#define true 1

int	count_args(const char *s)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i++])
	{
		if (s[i] == '%' && strchr("scpldz", s[i]))
		{
			if (s[i] == 'z' && s[i + 1] != 'u')
				continue ;
			n++;
		}
	}
	return (n);
}

void	ft_printf(const char *s, ...)
{
	va_list	argv;
	size_t	argn;
	size_t	i;

	argn = count_args(*s);
	i = 0;
	va_start(argv, argn);
	while (i < argn)
	{

	}
}
