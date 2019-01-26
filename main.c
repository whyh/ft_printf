
#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include "locale.h"

int main(void)
{
	setlocale(LC_ALL, "");
//	printf("%C\n", L'α');
//       printf("%.1S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	ft_printf("%.1S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
//	wchar_t a = '\316';
//	wchar_t b = '\261';
//	write(1, L'Î', 1);
//	write(1, L"", 1);
//	write(1, L"ą", 1);
//	ft_printf("α");
//	system("leaks a.out");
	return (1);
}
//basic 0
//und 12
//spead 22%
//mouli 1
