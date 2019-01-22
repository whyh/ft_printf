
#include "ft_printf/ft_printf.h"
#include <stdio.h>

int main(void)
{
	void	*p;
	int		i;

	i = 2;
	p = &i;
	printf("|%.21f|%-20s|%05.0d|\n", -5235234.123456789, "string", 1);
	ft_printf("|%.21f|%-20s|%05.0d|\n", -5235234.123456789, "string", 1);
	return (1);
}

//56 after dot
//21  are same