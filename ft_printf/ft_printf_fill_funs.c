/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fill_funs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_fill_flags(t_printf_funs *funs)
{
	funs['#'] = &ft_printf_flag_hash;
	funs['+'] = &ft_printf_flag_plus;
	funs[' '] = &ft_printf_flag_blank;
}

void	ft_printf_fill_convs(t_printf_funs *funs)
{
	funs['d'] = &ft_printf_convs_di;
	funs['i'] = &ft_printf_convs_di;
	funs['o'] = &ft_printf_conv_o;
	funs['u'] = &ft_printf_conv_u;
	funs['x'] = &ft_printf_conv_x;
	funs['X'] = &ft_printf_conv_cap_x;
	funs['c'] = &ft_printf_conv_c;
	funs['s'] = &ft_printf_conv_s;
	funs['p'] = &ft_printf_conv_p;
	funs['f'] = &ft_printf_conv_f;
}
