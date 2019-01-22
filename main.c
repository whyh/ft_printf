
#include "ft_printf/ft_printf.h"
#include <stdio.h>

int main(void)
{
	void	*p;
	int		i;

	i = 2;
	p = &i;
	   printf("   printf:-->%0-5s<--\n", "test");
	ft_printf("ft_printf:-->%0-5s<--\n", "test");
	return (1);
}

//56 after dot
//21  are same