#ifndef FT_PRINT_INTERNAL_H
# define FT_PRINT_INTERNAL_H
# define false 0
# define true 1
# define bool int
#include <stdarg.h>
#include <stdlib.h>

typedef enum {
	CHAR_INT,
	SHORT_INT,
	LONG,
	LLONG,
	LDOUBLE,
	SIZET,
	NONE
} ArgLength;

typedef enum {
	HEXINT,
	OCTINT,
	INT,
	LONG,
	STR,
	CHAR,
	PTR,
	DOUBLE
} ArgType;

typedef struct Arg {
	unsigned int	width;
	unsigned int	precision;
	enum ArgType	type;
	enum ArgLength	length;
	bool			is_uppercase;
	bool			is_signed;
} Arg;

/*	args.c	*/
enum ArgType	typeof(char c);
bool	is_valid_arg(const char *s, int i);
int		count_args(const char *s);
char	*get_arg_types(const char *s, int count);
char	**get_strs(va_list *argv, size_t argn, char *argtypes);

/*	parser.c	*/
Arg	parse_arg(const char *str, int *index, va_list *argv);

/*	writing.c	*/
void	write_formatted(const char *str, va_list *argv);
bool	write_arg(Arg arg, va_list *argv);

#endif