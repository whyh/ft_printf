
#include "ft_printf/ft_printf.h"
#include <stdio.h>

int main(void)
{
	void	*p;
	int		i;

	i = 2;
	p = &i;
//	   printf("%010lx\n", 42949672);
	ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	return (1);
}

//basic 20
//und 19
//spead 23%
//mouli 31

//    7fffffffffffffff LLONG
//0000ffffffffffffffff INT_MAX INT TYPES