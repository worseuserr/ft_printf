#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <stdarg.h>
#include <stdio.h>
#define false 0
#define true 1
#define bool int

void	parse_arg(char **out, va_list argv, char *argtypes, int i)
{
	printf("||%c||\n", argtypes[i]);
	if (argtypes[i] == 's')
		out[i] = strdup(va_arg(argv, char *));
	else if (argtypes[i] == 'd')
		out[i] = itoa(va_arg(argv, int), calloc(sizeof(int), 9), 10);
	printf(":%s:\n", out[i]);
}