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

static void	ft_printf_fill_flags(t_printf_funs *funs)
{
	funs['#'] = &ft_printf_hash;
	funs['+'] = &ft_printf_plus;
	funs[' '] = &ft_printf_blank;
	funs['0'] = &ft_printf_zero;
}

static void	ft_printf_fill_convs(t_printf_funs *funs)
{
	funs['d'] = &ft_printf_di;
	funs['i'] = &ft_printf_di;
	funs['o'] = &ft_printf_o;
	funs['u'] = &ft_printf_u;
	funs['x'] = &ft_printf_x;
	funs['X'] = &ft_printf_cap_x;
	funs['c'] = &ft_printf_c;
	funs['s'] = &ft_printf_s;
	funs['p'] = &ft_printf_p;
	funs['f'] = &ft_printf_f;
	funs['%'] = &ft_printf_mod0;
}

void		ft_printf_fill_funs(t_printf_funs **funs)
{
	*funs = ft_memalloc(sizeof(t_printf_funs *) * 256);
	ft_printf_fill_flags(*funs);
	ft_printf_fill_convs(*funs);
}
