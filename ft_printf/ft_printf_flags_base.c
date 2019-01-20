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

	if (!ft_is_included(PRINTF_CONVS_SIGNED, mods.conv))
			return (0);
	i = 0;
	while (buff->buff[i] != '\0' && buff->buff[i] != '-'
	&& !(buff->buff[i] >= '0' && buff->buff[i] <= '9'))
		++i;
	if (buff->buff[i] == '-')
		return (1);
	ft_strinject(&(buff->buff), "+", i);
	if (args)
		return (1);
	return (1);
}
