/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_mod0(va_list *args, t_printf_mods mods, t_printf_buff *buff,
		t_printf_funs *funs)
{
	if (funs[mods.length](args, mods, buff))
		return (1);
	buff->buff = ft_strdup(PRINTF_MOD0);
	return (1);
}

int		ft_printf_cap_u(va_list *args, t_printf_mods mods, t_printf_buff *buff,
		t_printf_funs *funs)
{
	char	*base;

	(void)funs;
	base = ft_printf_base(mods.conv);
	buff->buff = ft_itoabase_unsigned(base, va_arg(*args, ULL));
	return (1);
}

int		ft_printf_b(va_list *args, t_printf_mods mods, t_printf_buff *buff,
		t_printf_funs *funs)
{
	char	*base;

	base = ft_printf_base(mods.conv);
	if (funs[mods.length](args, mods, buff))
		return (1);
	buff->buff = ft_itoabase_unsigned(base, va_arg(*args, UI));
	return (1);
}
