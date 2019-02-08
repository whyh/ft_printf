
#include "ft_printf/ft_printf.h"
#include <stdio.h>

int main(void)
{
	ft_printf("the true symbols of %r", " new line \012, tab \011, start of text \002");
	ft_printf("5 in binary looks like %#b, and 9999 is definitely %b", 5, 9999);
	ft_printf("[blueb[white Ukra~][yellowb[whiteIne  ~][green,[red[bold %s~]", "yep");
	ft_printf("unspecified conversion %ll", 123);
	ft_printf("multiple specifications %+++.1.6.f", 99.5556);
	ft_printf("wrong specifications %+X", 775);
	ft_printf("wrong order of specification %hh3ll17S", L"¥ ¢ £ ¤ ¶");
	return (1);
}
