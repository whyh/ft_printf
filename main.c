
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include "locale.h"

int main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
//	   printf("%d", );
//	ft_printf("%S", "α");
	ft_printf("\n%d", 123);
	system("leaks a.out");
	return (1);
}

//basic 5
//und 12
//spead 22%
//mouli 18
