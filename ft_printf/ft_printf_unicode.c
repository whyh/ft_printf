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

static void		ft_printf_wchar(unsigned int ui, unsigned int mask[3],
				size_t size, char **tmp)
{
	if (size == 1)
		(*tmp)[0] = (char)ui;
	else if (size == 2)
	{
		(*tmp)[0] = (char)((mask[0] >> 8) | (((ui >> 6) << 27) >> 27));
		(*tmp)[1] = (char)(((mask[0] << 24) >> 24) | ((ui << 26) >> 26));
	}
	else if (size == 3)
	{
		(*tmp)[0] = (char)((mask[1] >> 16) | (((ui >> 12) << 28) >> 28));
		(*tmp)[1] = (char)(((mask[1] << 16) >> 24) | (((ui >> 6) << 26) >> 26));
		(*tmp)[2] = (char)(((mask[1] << 24) >> 24) | ((ui << 26) >> 26));
	}
	else if (size == 4)
	{
		(*tmp)[0] = (char)
		((((mask[2] >> 24) << 24) | (((ui >> 18) << 29) >> 29)));
		(*tmp)[1] = (char)
		((((mask[2] >> 16) << 24) >> 24) | (((ui >> 12) << 26) >> 26));
		(*tmp)[2] = (char)
		((((mask[2] >> 8) << 24) >> 24) | (((ui >> 6) << 26) >> 26));
		(*tmp)[3] = (char)(((mask[2] << 24) >> 24) | ((ui << 26) >> 26));
	}
	(*tmp)[size] = '\0';
}

int				ft_printf_cap_c(va_list *args, t_printf_mods *mods,
				t_printf_buff *node, t_printf_funs *funs)
{
	wchar_t			arg;
	size_t			size;
	unsigned int	mask[3];

	(void)funs;
	(void)mods;
	mask[0] = 49280;
	mask[1] = 14712960;
	mask[2] = 4034953344;
	arg = va_arg(*args, wchar_t);
	if (arg == '\0')
	{
		node->buff = ft_strdup(PRINTF_MOD3);
		return (1);
	}
	size = ft_printf_bit_size(arg);
	node->buff = ft_strnew(size);
	ft_printf_wchar((unsigned int)arg, mask, size, &(node->buff));
	return (1);
}

int				ft_printf_cap_s(va_list *args, t_printf_mods *mods,
				t_printf_buff *node, t_printf_funs *funs)
{
	wchar_t			*arg;
	char			*tmp;
	size_t			size;
	unsigned int	i[5];

	(void)funs;
	(void)mods;
	i[0] = 49280;
	i[1] = 14712960;
	i[2] = 4034953344;
	arg = va_arg(*args, wchar_t*);
	i[3] = 0;
	i[4] = 0;
	if (arg == NULL)
		node->buff = ft_strdup("(null)");
	while (arg != NULL && arg[i[3]])
	{
		size = ft_printf_bit_size(arg[i[3]]);
		tmp = ft_strnew(size);
		ft_printf_wchar((unsigned int)arg[i[3]], i, size, &tmp);
		ft_strinject(&(node->buff), tmp, (i[3])++ + i[4]);
		i[4] += size - 1;
		ft_strdel(&tmp);
	}
	return (1);
}
