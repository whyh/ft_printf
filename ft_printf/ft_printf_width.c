/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_width_minus(t_printf_mods mods, t_printf_buff *buff,
		int length)
{
	char	*prefix;
	char	*tmp;

	prefix = ft_strnew((size_t)mods.width - length);
	prefix = ft_memset(prefix, ' ', (size_t)(mods.width - length));
	tmp = ft_strjoin(buff->buff, prefix);
	ft_strdel(&(buff->buff));
	ft_strdel(&prefix);
	buff->buff = tmp;
}

static void	ft_printf_width_zero(t_printf_mods mods, t_printf_buff *buff,
		int length)
{
	char	*prefix;

	prefix = ft_strnew((size_t)mods.width - length);
	prefix = ft_memset(prefix, '0', (size_t)(mods.width - length));
	--length;
	while ((buff->buff[length] >= '0' && buff->buff[length] <= '9')
	|| (mods.conv == 'x' && ft_strin(HEX, buff->buff[length]))
	|| (mods.conv == 'X' && ft_strin(HEX_CAP, buff->buff[length])))
		--length;
	ft_strinject(&buff->buff, prefix, (size_t)(length) + 1);
	ft_strdel(&prefix);
}

static void	ft_printf_width_std(t_printf_mods mods, t_printf_buff *buff,
		int length)
{
	char	*prefix;
	char	*tmp;

	prefix = ft_strnew((size_t)mods.width - length);
	prefix = ft_memset(prefix, ' ', (size_t)(mods.width - length));
	tmp = ft_strjoin(prefix, buff->buff);
	ft_strdel(&(buff->buff));
	ft_strdel(&prefix);
	buff->buff = tmp;
}

void		ft_printf_width(t_printf_mods mods, t_printf_buff *buff)
{
	int		length;

	length = (int)ft_strlen(buff->buff);
	if (length >= mods.width)
		return ;
	if (ft_strin(mods.flags, '0') && mods.prec == 1
		&& !ft_strin(mods.flags, '-'))
		ft_printf_width_zero(mods, buff, length);
	else if (ft_strin(mods.flags, '-'))
		ft_printf_width_minus(mods, buff, length);
	else
		ft_printf_width_std(mods, buff, length);
}
