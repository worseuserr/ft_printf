#include <stdlib.h>
#include <stdarg.h>
#include "internal\common.h"
#include "..\include\ft_printf.h"

void	ft_printf(const char *str, ...)
{
	va_list	argv;
	size_t	argn;
	char	*argtypes;
	char	**strs;

	argn = count_args(str);
	argtypes = get_arg_types(str, argn);
	va_start(argv, str);
	strs = get_strs(&argv, argn, argtypes);
	write_formatted(str, strs);
	va_end(argv);
	free(argtypes);
	while(argn-- > 0)
		free(strs[argn]);
	free(strs);
}
