#include <stdlib.h>
#include <stdarg.h>
#include "internal\common.h"
#include "..\include\ft_printf.h"

void	ft_printf(const char *str, ...)
{
	va_list	argv;
	size_t	argn;

	va_start(argv, str);
	write_formatted(str, *argv);
	va_end(argv);
}
