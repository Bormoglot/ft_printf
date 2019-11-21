#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		a;
	char	b;
	//float	c;
	int		printf_charcount;
	int		ft_printf_charcount;

	a = 3;
	b = 'Z';
	//c = 2.2;
	printf("Original:\n");
	printf_charcount = printf("int is <% 3d>, char is <%-20c>. End.\n", a, b);
	printf("printf return value: <%d>\n", printf_charcount);
	printf("\n");
	printf("FT:\n");
	ft_printf_charcount = ft_printf("int is <%d>, char is <%-20c>. End.\n", a, b);
	printf("ft_printf return value: <%d>\n", ft_printf_charcount);
	return (0);
}
