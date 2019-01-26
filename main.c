
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include "locale.h"

int main(void)
{
	setlocale(LC_ALL, "");
//	printf("%C\n", L'α');
	   printf("{%05.c}\n", 0);
	ft_printf("{%05.c}\n", 0);
//	wchar_t a = '\316';
//	wchar_t b = '\261';
//	write(1, L'Î', 1);
//	write(1, L"", 1);
//	write(1, L"ą", 1);
//	ft_printf("α");
//	system("leaks a.out");
	return (1);
}
//basic 5
//und 12
//spead 22%
//mouli 14
