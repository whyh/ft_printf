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

int		ft_printf_0(va_list *args, t_printf_mods mods, t_printf_buff *node)
{
	(void)args;
	(void)mods;
	(void)node;
	return (0);
}

char	*ft_printf_base(char conv)
{
	if (conv == 'X')
		return (HEX_CAP);
	if (conv == 'x' || conv == 'p')
		return (HEX);
	if (conv == 'o' || conv == 'O')
		return (OCT);
	if (conv == 'b')
		return (BINARY);
	else
		return (DEC);
}

char	*ft_printf_base_prefix(t_printf_mods mods, t_printf_buff *node)
{
	if ((mods.conv == 'X' || mods.conv == 'x')
	&& ((node->buff[0] == '0' && node->buff[1] == '\0') || mods.prec == 0))
		return (NULL);
	if ((mods.conv == 'o' || mods.conv == 'O' || mods.conv == 'b')
	&& node->buff[0] == '0')
		return (NULL);
	if (mods.conv == 'X')
		return ("0X");
	if (mods.conv == 'x' || mods.conv == 'p')
		return ("0x");
	if (mods.conv == 'o' || mods.conv == 'O')
		return ("0");
	if (mods.conv == 'b')
		return ("0b");
	else
		return (NULL);
}

size_t	ft_printf_putstr(char *s)
{
	size_t	length;

	if (s == NULL)
		return (0);
	length = 0;
	while (s[length])
	{
		if (ft_strin(PRINTF_MOD3, s[length]))
			s[length] = '\0';
		++length;
	}
	write(1, s, length);
	return (length);
}

void	ft_printf_get_asterix( t_printf_mods *mods, va_list *args,
		char *mod, char **format)
{
	int		i;

	(*format)++;
	i = va_arg(*args, int);
	if (ft_strequ(mod, "width"))
	{
		if (i < 0)
		{
			i *= -1;
			ft_strinject(&(mods->flags), "-", 0);
		}
		mods->width = i;
	}
	else if (ft_strequ(mod, "prec"))
	{
		if (i >= 0)
			mods->prec = i;
		else
			mods->prec_spec = 0;
	}
	else if (ft_strequ(mod, "flags"))
		ft_strinject(&(mods->flags),(char*)&i , 1);
	else if (ft_strequ(mod, "conv"))
		mods->conv = (char)i;
}