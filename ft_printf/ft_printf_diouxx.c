/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diouxx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_di(va_list *args, t_printf_mods mods, t_printf_buff *buff,
		t_printf_funs *funs)
{
	char	*base;

	base = ft_printf_base(mods.conv);
	if (funs[mods.length](args, mods, buff))
		return (1);
	buff->buff = ft_itoabase(base, va_arg(*args, int));
	return (1);
}

int		ft_printf_o(va_list *args, t_printf_mods mods, t_printf_buff *buff,
		t_printf_funs *funs)
{
	char	*base;

	base = ft_printf_base(mods.conv);
	if (funs[mods.length](args, mods, buff))
		return (1);
	buff->buff = ft_itoabase_unsigned(base, va_arg(*args, UI));
	return (1);
}

int		ft_printf_u(va_list *args, t_printf_mods mods, t_printf_buff *buff,
		t_printf_funs *funs)
{
	char	*base;

	base = ft_printf_base(mods.conv);
	if (funs[mods.length](args, mods, buff))
		return (1);
	buff->buff = ft_itoabase_unsigned(base, va_arg(*args, UI));
	return (1);
}

int		ft_printf_x(va_list *args, t_printf_mods mods, t_printf_buff *buff,
		t_printf_funs *funs)
{
	char	*base;

	base = ft_printf_base(mods.conv);
	if (funs[mods.length](args, mods, buff))
		return (1);
	buff->buff = ft_itoabase_unsigned(base, va_arg(*args, UI));
	return (1);
}

int		ft_printf_cap_x(va_list *args, t_printf_mods mods, t_printf_buff *buff,
		t_printf_funs *funs)
{
	char	*base;

	base = ft_printf_base(mods.conv);
	if (funs[mods.length](args, mods, buff))
		return (1);
	buff->buff = ft_itoabase_unsigned(base, va_arg(*args, UI));
	return (1);
}
