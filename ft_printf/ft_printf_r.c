/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_chrunprint(t_printf_buff *node, char *arg, char *to_print,
			char *unprint)
{
	int		i;
	size_t	u;
	int		i2;

	i = 0;
	u = 0;
	while (arg[i])
		if (ft_iswhitespace(arg[i++]))
			++u;
	node->buff = ft_strnew(u + i);
	i = -1;
	u = 0;
	while (arg[++i])
	{
		if (ft_strin(unprint, arg[i]))
		{
			i2 = 0;
			node->buff[u++] = '\\';
			while (arg[i] != unprint[i2])
				++i2;
			node->buff[u++] = to_print[i2];
		}
		else
			node->buff[u++] = arg[i];
	}
}

int			ft_printf_r(va_list *args, t_printf_mods *mods, t_printf_buff *node,
			t_printf_funs *funs)
{
	char	*arg;
	char	*to_print;
	char	*unprint;

	if (funs[mods->length](args, *mods, node))
		return (1);
	arg = va_arg(*args, char *);
	if (arg == NULL)
		node->buff = ft_strdup("(null)");
	else
	{
		to_print = ft_strdup("abfnrtv");
		unprint = ft_strdup("\a\b\f\n\r\t\v");
		ft_printf_chrunprint(node, arg, to_print, unprint);
		ft_strdel(&to_print);
		ft_strdel(&unprint);
	}
	return (1);
}
