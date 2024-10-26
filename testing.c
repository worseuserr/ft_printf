#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#define false 0
#define true 1
#define bool int

char	*get_ptrval(void *ptr)
{
    unsigned long long	addr;
    int					num_digits = 16;
    char				*hex_digits;
	char				base[16];

	addr = (unsigned long long)ptr;
	hex_digits = calloc(16, sizeof(char));
	memcpy(base, "0123456789ABCDEF", 16);
    while (num_digits-- - 1 >= 0)
	{
        unsigned int digit = addr & 0xf;
        hex_digits[num_digits] = base[digit];
        addr >>= 4;
    }
	return (hex_digits);
}

int	main(void)
{
	int x = 42;
	void *p = (void *)&x;
	printf("x is at [%p]\n", p);
	write(1, get_ptrval(p), 16);

	return (0);
}

