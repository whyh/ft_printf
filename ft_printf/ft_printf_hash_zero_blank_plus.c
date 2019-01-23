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
	if (mods.conv == '%')
		return (1);
	if (!ft_strin(PRINTF_SN, mods.conv))
		return (0);
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

int	ft_printf_blank(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	size_t	i;
	char	*tmp;

	(void)args;
	if (mods.conv == '%')
		return (1);
	if (!ft_strin(PRINTF_SN, mods.conv))
		return (0);
	if (ft_strin(mods.flags, '+'))
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

int	ft_printf_hash(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	char	*tmp;

	(void)args;
	tmp = NULL;
	if (!ft_strin(PRINTF_NDEC, mods.conv))
		return (0);
	if (mods.conv == 'o' && (buff->buff)[0] != '0')
		tmp = ft_strjoin("0", buff->buff);
	else if ((mods.conv == 'X' || mods.conv == 'x') && mods.prec == 0)
		return (1);
	else if (mods.conv == 'x' && !((buff->buff)[0] == '0'
	&& buff->buff[1] == '\0'))
		tmp = ft_strjoin("0x", buff->buff);
	else if (mods.conv == 'X' && !((buff->buff)[0] == '0'
	&& buff->buff[1] == '\0'))
		tmp = ft_strjoin("0X", buff->buff);
	else if (ft_strin(PRINTF_FLOAT, mods.conv) && !ft_strin(buff->buff, '.'))
		tmp = ft_strjoin(buff->buff, ".");
	if (tmp != NULL)
	{
		ft_strdel(&(buff->buff));
		buff->buff = tmp;
	}
	return (1);
}

int	ft_printf_zero(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	(void)args;
	(void)buff;
	if (ft_strin(mods.flags, '0') && !ft_strin(PRINTF_FLOAT, mods.conv)
	&& !ft_strin(PRINTF_MOD0, mods.conv) && !ft_strin(PRINTF_USN, mods.conv)
	&& !ft_strin(PRINTF_SN, mods.conv) && !ft_strin(PRINTF_NDEC, mods.conv))
		return (0);
	return (1);
}
