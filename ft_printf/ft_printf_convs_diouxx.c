/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convs_diouxx.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_convs_di(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	if (mods.length[0] == '\0')
		buff->buff = ft_itoabase("0123456789", va_arg(*args, int));
	else if (mods.length[0] == 'l' && mods.length[1] == 'l')
		buff->buff = ft_itoabase("0123456789", va_arg(*args, long long));
	else if (mods.length[0] == 'h' && mods.length[1] == 'h')
		buff->buff = ft_itoabase("0123456789", (char)va_arg(*args, int));
	else if (mods.length[0] == 'l')
		buff->buff = ft_itoabase("0123456789", va_arg(*args, long));
	else if (mods.length[0] == 'h')
		buff->buff = ft_itoabase("0123456789", (short)va_arg(*args, int));
	return (1);
}

int		ft_printf_conv_o(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	if (mods.length[0] == '\0')
		buff->buff =
		ft_itoabase_unsigned("01234567", va_arg(*args, unsigned int));
	else if (mods.length[0] == 'l' && mods.length[1] == 'l')
		buff->buff =
		ft_itoabase_unsigned("01234567", va_arg(*args, unsigned long long));
	else if (mods.length[0] == 'h' && mods.length[1] == 'h')
		buff->buff =
		ft_itoabase_unsigned("01234567", (unsigned char)va_arg(*args, int));
	else if (mods.length[0] == 'l')
		buff->buff =
		ft_itoabase_unsigned("01234567", va_arg(*args, unsigned long));
	else if (mods.length[0] == 'h')
		buff->buff =
		ft_itoabase_unsigned("01234567", (unsigned short)va_arg(*args, int));
	return (1);
}

int		ft_printf_conv_u(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	if (mods.length[0] == '\0')
		buff->buff =
		ft_itoabase_unsigned("0123456789", va_arg(*args, unsigned int));
	else if (mods.length[0] == 'l' && mods.length[1] == 'l')
		buff->buff =
		ft_itoabase_unsigned("0123456789", va_arg(*args, unsigned long long));
	else if (mods.length[0] == 'h' && mods.length[1] == 'h')
		buff->buff =
		ft_itoabase_unsigned("0123456789", (unsigned char)va_arg(*args, int));
	else if (mods.length[0] == 'l')
		buff->buff =
		ft_itoabase_unsigned("0123456789", va_arg(*args, unsigned long));
	else if (mods.length[0] == 'h')
		buff->buff =
		ft_itoabase_unsigned("0123456789", (unsigned short)va_arg(*args, int));
	return (1);
}

int		ft_printf_conv_x(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	if (mods.length[0] == '\0')
		buff->buff =
		ft_itoabase_unsigned(HEX, va_arg(*args, unsigned int));
	else if (mods.length[0] == 'l' && mods.length[1] == 'l')
		buff->buff =
		ft_itoabase_unsigned(HEX, va_arg(*args, unsigned long long));
	else if (mods.length[0] == 'h' && mods.length[1] == 'h')
		buff->buff =
		ft_itoabase_unsigned(HEX, (unsigned char)va_arg(*args, int));
	else if (mods.length[0] == 'l')
		buff->buff =
		ft_itoabase_unsigned(HEX, va_arg(*args, unsigned long));
	else if (mods.length[0] == 'h')
		buff->buff =
		ft_itoabase_unsigned(HEX, (unsigned short)va_arg(*args, int));
	return (1);
}

int		ft_printf_conv_cap_x(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	if (mods.length[0] == '\0')
		buff->buff =
		ft_itoabase_unsigned(HEX_CAP, va_arg(*args, unsigned int));
	else if (mods.length[0] == 'l' && mods.length[1] == 'l')
		buff->buff =
		ft_itoabase_unsigned(HEX_CAP, va_arg(*args, unsigned long long));
	else if (mods.length[0] == 'h' && mods.length[1] == 'h')
		buff->buff =
		ft_itoabase_unsigned(HEX_CAP, (unsigned char)va_arg(*args, int));
	else if (mods.length[0] == 'l')
		buff->buff =
		ft_itoabase_unsigned(HEX_CAP, va_arg(*args, unsigned long));
	else if (mods.length[0] == 'h')
		buff->buff =
		ft_itoabase_unsigned(HEX_CAP, (unsigned short)va_arg(*args, int));
	return (1);
}
