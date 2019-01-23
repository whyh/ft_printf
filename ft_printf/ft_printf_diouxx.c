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

int		ft_printf_di(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	if (mods.length[0] == '\0')
		buff->buff = ft_itoabase(DEC, va_arg(*args, int));
	else if (mods.length[0] == 'l' && mods.length[1] == 'l')
		buff->buff = ft_itoabase(DEC, va_arg(*args, LL));
	else if (mods.length[0] == 'h' && mods.length[1] == 'h')
		buff->buff = ft_itoabase(DEC, (char)va_arg(*args, int));
	else if (mods.length[0] == 'l')
		buff->buff = ft_itoabase(DEC, va_arg(*args, L));
	else if (mods.length[0] == 'h')
		buff->buff = ft_itoabase(DEC, (S)va_arg(*args, int));
	return (1);
}

int		ft_printf_o(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	if (mods.length[0] == '\0')
		buff->buff = ft_itoabase_unsigned(OCT, va_arg(*args, UI));
	else if (mods.length[0] == 'l' && mods.length[1] == 'l')
		buff->buff = ft_itoabase_unsigned(OCT, va_arg(*args, ULL));
	else if (mods.length[0] == 'h' && mods.length[1] == 'h')
		buff->buff = ft_itoabase_unsigned(OCT, (UC)va_arg(*args, int));
	else if (mods.length[0] == 'l')
		buff->buff = ft_itoabase_unsigned(OCT, va_arg(*args, UL));
	else if (mods.length[0] == 'h')
		buff->buff = ft_itoabase_unsigned(OCT, (US)va_arg(*args, int));
	return (1);
}

int		ft_printf_u(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	if (mods.length[0] == '\0')
		buff->buff = ft_itoabase_unsigned(DEC, va_arg(*args, UI));
	else if (mods.length[0] == 'l' && mods.length[1] == 'l')
		buff->buff = ft_itoabase_unsigned(DEC, va_arg(*args, ULL));
	else if (mods.length[0] == 'h' && mods.length[1] == 'h')
		buff->buff = ft_itoabase_unsigned(DEC, (UC)va_arg(*args, int));
	else if (mods.length[0] == 'l')
		buff->buff = ft_itoabase_unsigned(DEC, va_arg(*args, UL));
	else if (mods.length[0] == 'h')
		buff->buff = ft_itoabase_unsigned(DEC, (US)va_arg(*args, int));
	return (1);
}

int		ft_printf_x(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	if (mods.length[0] == '\0')
		buff->buff = ft_itoabase_unsigned(HEX, va_arg(*args, UI));
	else if (mods.length[0] == 'l' && mods.length[1] == 'l')
		buff->buff = ft_itoabase_unsigned(HEX, va_arg(*args, ULL));
	else if (mods.length[0] == 'h' && mods.length[1] == 'h')
		buff->buff = ft_itoabase_unsigned(HEX, (UC)va_arg(*args, int));
	else if (mods.length[0] == 'l')
		buff->buff = ft_itoabase_unsigned(HEX, va_arg(*args, UL));
	else if (mods.length[0] == 'h')
		buff->buff = ft_itoabase_unsigned(HEX, (US)va_arg(*args, int));
	return (1);
}

int		ft_printf_cap_x(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	if (mods.length[0] == '\0')
		buff->buff = ft_itoabase_unsigned(HEX_CAP, va_arg(*args, UI));
	else if (mods.length[0] == 'l' && mods.length[1] == 'l')
		buff->buff = ft_itoabase_unsigned(HEX_CAP, va_arg(*args, ULL));
	else if (mods.length[0] == 'h' && mods.length[1] == 'h')
		buff->buff = ft_itoabase_unsigned(HEX_CAP, (UC)va_arg(*args, int));
	else if (mods.length[0] == 'l')
		buff->buff = ft_itoabase_unsigned(HEX_CAP, va_arg(*args, UL));
	else if (mods.length[0] == 'h')
		buff->buff = ft_itoabase_unsigned(HEX_CAP, (US)va_arg(*args, int));
	return (1);
}
