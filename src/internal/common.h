#ifndef FT_PRINT_INTERNAL_H
# define FT_PRINT_INTERNAL_H
# define false 0
# define true 1
# define bool int
#include <stdarg.h>
#include <stdlib.h>

/*	args.c	*/
bool	is_valid_arg(const char *s, int i);
int		count_args(const char *s);
char	*get_arg_types(const char *s, int count);
char	**get_strs(va_list *argv, size_t argn, char *argtypes);

/*	parser.c	*/
void	parse_arg(char **out, va_list *argv, char *argtypes, int i);

/*	writing.c	*/
void	write_formatted(const char *s, char **strs);
bool	write_arg(const char *s, char *str, int i);

#endif