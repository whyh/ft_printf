
#include "ft_printf/ft_printf.h"
#include <stdio.h>

int main(void)
{
	void	*p;
	int		i;

	i = 2;
	p = &i;
	   printf("%#.o\n", 0);
//	ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	return (1);
}

//basic 20
//und 19
//spead 27%
//mouli 31

//    7fffffffffffffff LLONG
//0000ffffffffffffffff INT_MAX INT TYPES