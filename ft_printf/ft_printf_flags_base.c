/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_flag_plus(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	size_t	i;
	char	*tmp;

	(void)args;
	if (mods.conv == '%')
		return (1);
	if (!ft_is_included(PRINTF_CONVS_SN, mods.conv))
			return (0);//handle error
	i = 0;
	while (buff->buff[i] != '\0' && buff->buff[i] != '-'
	&& !(buff->buff[i] >= '0' && buff->buff[i] <= '9'))
		++i;
	if (buff->buff[i] == '-')
		return (1);
	tmp = ft_strjoin("+", buff->buff);
	ft_strdel(&(buff->buff));
	buff->buff = tmp;
	return (1);
}

int	ft_printf_flag_blank(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	size_t	i;
	char	*tmp;

	(void)args;
	if (mods.conv == '%')
		return (1);
	if (!ft_is_included(PRINTF_CONVS_SN, mods.conv))
		return (0);//handle error
	if (ft_is_included(mods.flags, '+'))
		return (1);
	i = 0;
	while (buff->buff[i] != '\0' && buff->buff[i] != '-'
	&& !(buff->buff[i] >= '0' && buff->buff[i] <= '9'))
		++i;
	if (buff->buff[i] == '-')
		return (1);
	tmp = ft_strjoin(" ", buff->buff);
	ft_strdel(&(buff->buff));
	buff->buff = tmp;
	return (1);
}

int	ft_printf_flag_hash(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	char	*tmp;

	(void)args;
	tmp = NULL;
	if (!ft_is_included(PRINTF_CONVS_UNS, mods.conv) || mods.conv == 'u')
		return (0);//handle error
	if (mods.conv == 'o' && (buff->buff)[0] != '0')
		tmp = ft_strjoin("0", buff->buff);
	else if (mods.conv == 'x' && !((buff->buff)[0] == '0' && buff->buff[1] == '\0'))
		tmp = ft_strjoin("0x", buff->buff);
	else if (mods.conv == 'X' && !((buff->buff)[0] == '0' && buff->buff[1] == '\0'))
		tmp = ft_strjoin("0X", buff->buff);
	else if (mods.conv == 'f' && !ft_is_included(buff->buff, '.'))
		tmp = ft_strjoin(buff->buff, ".");
	if (tmp != NULL)
	{
		ft_strdel(&(buff->buff));
		buff->buff = tmp;
	}
	return (1);
}
