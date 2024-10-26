#include <stdlib.h>
#include <stdio.h>
// #include "src\ft_printf.c"

void	ft_printf(const char *s, ...);

int	main(void)
{
	ft_printf("the num is: %d : %s\n", 20, "numbr");
	ft_printf("what the %s vro%s", "freak", "!");
	return (0);
}