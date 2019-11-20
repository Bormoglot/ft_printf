#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		a;
	char	b;
	float	c;
	int		printf_charcount;
	int		ft_printf_charcount;

	a = 123;
	b = 'Z';
	c = 2.2;
	printf("Original:\n");
	printf_charcount = printf("int is <%.5d>, char is <%c>, float is <%.1f>. End.\n", a, b, c);
	printf("printf return value: <%d>\n", printf_charcount);
	printf("\n");
	printf("FT:\n");
	ft_printf_charcount = ft_printf("int is <%d>, char is <%c>. End.\n", a, b);
	printf("ft_printf return value: <%d>\n", ft_printf_charcount);
	return (0);
}
