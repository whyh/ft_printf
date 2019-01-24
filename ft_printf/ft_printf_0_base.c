/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_0_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_0(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	(void)args;
	(void)mods;
	(void)buff;
	return (0);
}

char	*ft_printf_base(char conv)
{
	if (conv == 'X')
		return (HEX_CAP);
	if (conv == 'x' || conv == 'p')
		return (HEX);
	if (conv == 'o')
		return (OCT);
	if (conv == 'b')
		return (BINARY);
	else
		return (DEC);
}

char	*ft_printf_base_prefix(t_printf_mods mods, t_printf_buff *buff)
{
	if ((mods.conv == 'X' || mods.conv == 'x')
	&& ((buff->buff[0] == '0' && buff->buff[1] == '\0') || mods.prec == 0))
		return (NULL);
	if (mods.conv == 'o' && buff->buff[0] == '0')
		return (NULL);
	if (mods.conv == 'X')
		return ("0X");
	if (mods.conv == 'x' || mods.conv == 'p')
		return ("0x");
	if (mods.conv == 'o')
		return ("0");
	if (mods.conv == 'b')
		return ("0b");
	else
		return (NULL);
}
