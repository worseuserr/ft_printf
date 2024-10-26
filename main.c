#include <stdlib.h>
#include <stdio.h>
// debug
// #include "src\ft_printf.c"
// #include "src\parser.c"
// #include "src\writing.c"

void	ft_printf(const char *s, ...);

int	main(void)
{
	int x = 42;
	ft_printf("the num is: %d : %s\n", -20, "numbr");
	ft_printf("what the %s vro%s\n", "freak", "!");
	ft_printf("x is at [%p]", &x);
	return (0);
}