/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:00:47 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/08 19:00:47 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <stdio.h>

int main(void)
{
	ft_printf("the true symbols of %r", " new line \012, tab \011, start of text \002\n");
	ft_printf("5 in binary looks like %#b, and 9999 is definitely %b\n", 5, 9999);
	ft_printf("[blueb[white Ukra~][yellowb[whiteIne  ~][green,[red[bold %s~]\n", "yep");
	ft_printf("unspecified conversion %ll\n", 123);
	ft_printf("multiple specifications %+++.1.6.f\n", 99.5556);
	ft_printf("wrong specifications %+X\n", 775);
	ft_printf("wrong order of specification %hh3ll17S\n", L"¥ ¢ £ ¤ ¶");
	return (1);
}
