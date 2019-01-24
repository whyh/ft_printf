/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hash_zero_blank_plus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_plus(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	size_t	i;
	char	*tmp;

	(void)args;
	if (!ft_strin(PRINTF_SN, mods.conv))
		return (1);
	i = 0;
	while (buff->buff[i] != '\0' && buff->buff[i] != '-'
	&& !ft_isdigit(buff->buff[i]))
		++i;
	if (buff->buff[i] == '-')
		return (1);
	tmp = ft_strjoin("+", buff->buff);
	ft_strdel(&(buff->buff));
	buff->buff = tmp;
	return (1);
}

int	ft_printf_blank(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	size_t	i;
	char	*tmp;

	(void)args;
	if (!ft_strin(PRINTF_SN, mods.conv) || ft_strin(mods.flags, '+'))
		return (1);
	i = 0;
	while (buff->buff[i] != '\0' && buff->buff[i] != '-'
	&& !ft_isdigit(buff->buff[i]))
		++i;
	if (buff->buff[i] == '-')
		return (1);
	tmp = ft_strjoin(" ", buff->buff);
	ft_strdel(&(buff->buff));
	buff->buff = tmp;
	return (1);
}

int	ft_printf_hash(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	size_t	i;

	(void)args;
	if (ft_strin(PRINTF_NDEC, mods.conv))
	{
		i = 0;
		while (buff->buff[i]
		&& !ft_strin(ft_printf_base(mods.conv), buff->buff[i]))
			++i;
		ft_strinject(&(buff->buff), ft_printf_base_prefix(mods, buff), i);
	}
	else if (ft_strin(PRINTF_FLOAT, mods.conv) && !ft_strin(buff->buff, '.'))
		ft_strinject(&(buff->buff), ".", ft_strlen(buff->buff) - 1);
	return (1);
}

int	ft_printf_zero(t_printf_mods mods)
{
	if (ft_strin(mods.flags, '0') && mods.prec == 1
	&& (ft_strin(PRINTF_FLOAT, mods.conv) || ft_strin(PRINTF_MOD0, mods.conv)
	|| ft_strin(PRINTF_USN, mods.conv) || ft_strin(PRINTF_SN, mods.conv)
	|| ft_strin(PRINTF_NDEC, mods.conv)))
		return (1);
	return (0);
}
