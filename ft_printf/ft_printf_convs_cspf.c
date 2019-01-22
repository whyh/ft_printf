/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convs_cspf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_printf_conv_c(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	char	arg;

	if ((mods.length)[0] != '\0')
		return (0);//handle error
	arg = (char)va_arg(*args, int);
	buff->buff = ft_strnew(1);
	(buff->buff)[0] = arg;
	return (1);
}

int	ft_printf_conv_s(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	char	*arg;

	if ((mods.length)[0] != '\0')
		return (0);//handle error
	arg = va_arg(*args, char*);
	buff->buff = arg;
	return (1);
}

int	ft_printf_conv_p(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	char	*tmp;

	if ((mods.length)[0] != '\0')
		return (0);//handle error
	buff->buff = ft_itoabase_unsigned(HEX, va_arg(*args, unsigned long long));
	if ((buff->buff)[0] == '\0')
		tmp = ft_strjoin("0x0", buff->buff);
	else
		tmp = ft_strjoin("0x", buff->buff);
	ft_strdel(&(buff->buff));
	buff->buff = tmp;
	return (1);
}

int	ft_printf_conv_f(va_list *args, t_printf_mods mods, t_printf_buff *buff)
{
	long double	arg;
	long long	a_args[4];
	char		*tmp1;
	char		*tmp2;
	char		*tmp3;

	if (mods.length[1] == 'l' || mods.length[0] == 'h')
		return (0);//handle error
	if (mods.length[0] == 'L')
		arg = va_arg(*args, long double);
	else
		arg = va_arg(*args, double);
	tmp3 = NULL;
	if (arg < 0)
	{
		arg = -arg;
		tmp3 = ft_strdup("-");
	}
	ft_printf_split_float(arg, a_args);
	buff->buff = ft_itoabase("0123456789", a_args[0]);
	tmp1 = ft_itoabase("0123456789", a_args[1]);
	tmp2 = ft_strjoin(buff->buff, ".");
	ft_strdel(&(buff->buff));
	buff->buff = ft_strjoin(tmp2, tmp1);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	//
	tmp1 = ft_itoabase("0123456789", a_args[2]);
	tmp2 = ft_strjoin(buff->buff, tmp1);
	ft_strdel(&tmp1);
	ft_strdel(&(buff->buff));
	tmp1 = ft_itoabase("0123456789", a_args[3]);
	buff->buff = ft_strjoin(tmp2, tmp1);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	//
	tmp1 = ft_strjoin(tmp3, buff->buff);
	ft_strdel(&(buff->buff));
	buff->buff = tmp1;
	return (1);
}

void		ft_printf_split_float(long double arg, long long a_args[4])
{
	a_args[0] = (long long)arg;
	arg -= a_args[0];
//	if (arg < 0)
//	{
//		a_args[0] -= 1;
//		arg += 1;
//	}
	arg = (arg * 1000000000000000000);
	a_args[1] = (long long)arg;
	arg -= a_args[1];
	arg = (arg * 1000000000000000000);
	a_args[2] = (long long)arg;
	arg -= a_args[2];
	arg = (arg * 1000000000000000000);
	a_args[3] = (long long)arg;
}
