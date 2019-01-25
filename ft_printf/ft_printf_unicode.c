/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static size_t	ft_printf_bit_size(wchar_t arg)
{
	unsigned int	ui;
	size_t			i;

	ui = (unsigned int)arg;
	i = 0;
	while (ui > 0)
	{
		++i;
		ui = ui >> 1;
	}
	if (i <= 7)
		return (1);
	else if (i <= 11)
		return (2);
	else if (i <= 16)
		return (3);
	else if (i <= 21)
		return (4);
	else
		return (0);
}

static void		ft_printf_bit_char_2(size_t size, unsigned int mask[3],
				unsigned int ui, wchar_t *ret)
{
	unsigned int	i;

	i = 0;
	if (size == 2)
	{
		ret[i++] = (mask[0] >> 8) | (((ui >> 6) << 27) >> 27);
		ret[i] = ((mask[0] << 24) >> 24) | ((ui << 26) >> 26);
	}
	else if (size == 3)
	{
		ret[i++] = (mask[1] >> 16) | (((ui >> 12) << 28) >> 28);
		ret[i++] = ((mask[1] << 16) >> 24) | (((ui >> 6) << 26) >> 26);
		ret[i] = ((mask[1] << 24) >> 24) | ((ui << 26) >> 26);
	}
	else if (size == 4)
	{
		ret[i++] = (((mask[2] >> 24) << 24) | (((ui >> 18) << 29) >> 29));
		ret[i++] = (((mask[2] >> 16) << 24) >> 24) | (((ui >> 12) << 26) >> 26);
		ret[i++] = (((mask[2] >> 8) << 24) >> 24) | (((ui >> 6) << 26) >> 26);
		ret[i] = ((mask[2] << 24) >> 24) | ((ui << 26) >> 26);
	}
}

static wchar_t	*ft_printf_wchar(wchar_t arg)
{
	wchar_t			*ret;
	unsigned int	mask[3];
	unsigned int	ui;
	unsigned int 	i;
	size_t			size;

	mask[0] = 49280;
	mask[1] = 14712960;
	mask[2] = 4034953344;
	i = 0;
	size = ft_printf_bit_size(arg);
	ret = ft_wstrnew(size);
	ui = (unsigned int)arg;
	if (size == 0)
		return (NULL);
	else if (size == 1)
		ret[i] = ui;
	else
		ft_printf_bit_char_2(size, mask, ui, ret);
	return (ret);
}

int			ft_printf_cap_c(va_list *args, t_printf_mods *mods,
			t_printf_buff *node, t_printf_funs *funs)
{
	wchar_t	arg;

	(void)funs;
	(void)mods;
	arg = va_arg(*args, wchar_t);
	node->wbuff = ft_printf_wchar(arg);
	return (1);
}

int			ft_printf_cap_s(va_list *args, t_printf_mods *mods,
			t_printf_buff *node, t_printf_funs *funs)
{
	wchar_t	*arg;
	wchar_t	*tmp;
	size_t 	i;

	(void)funs;
	(void)mods;
	arg = va_arg(*args, wchar_t*);
	i = 0;
	while (arg[i])
	{
		tmp = ft_printf_wchar(arg[i]);
		ft_wstrinject(&(node->wbuff), tmp, 0);
		ft_wstrdel(&tmp);
		++i;
	}
	return (1);
}
