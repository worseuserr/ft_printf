#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#define false 0
#define true 1
#define bool int

bool	is_valid_arg(const char *s, int i)
{
	if (s[i] == '%' && strchr("scpldz", s[i + 1]))
	{
		if (s[i] == 'z' && s[i + 1] != 'u')
			return (false);
		return (true);
	}
	return (false);
}

int	main(void)
{
	printf("%d", is_valid_arg("%s", 0));
	return (0);
}