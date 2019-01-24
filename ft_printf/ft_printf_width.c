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
	while (ft_isdigit(buff->buff[length]) || (ft_strin(PRINTF_NDEC, mods.conv)
	&& ft_strin(ft_printf_base(mods.conv), buff->buff[length])))
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
	if (ft_strin(mods.flags, '-'))
		ft_printf_width_minus(mods, buff, length);
	else if (ft_printf_zero(mods))
		ft_printf_width_zero(mods, buff, length);
	else
		ft_printf_width_std(mods, buff, length);
}
