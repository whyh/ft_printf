
#include "ft_printf/ft_printf.h"
#include <stdio.h>

int main(void)
{
	void	*p;
	int		i;

	i = 2;
	p = &i;
//	   printf("%jd", );
	ft_printf("%0x", 5);
	return (1);
}

//basic 5
//und 19
//spead 27% / 22
//mouli 27

//    7fffffffffffffff LLONG
//0000ffffffffffffffff INT_MAX INT TYPES