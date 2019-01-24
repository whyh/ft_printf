/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_exec(t_printf_mods mods, va_list *args,
			t_printf_buff *buff)
{
	static t_printf_funs	*funs = NULL;
	static t_printf_convs	*convs = NULL;
	int						i;

	if (!funs || !convs)
		ft_printf_fill_funs_convs(&funs, &convs);
	if (!convs[(int)mods.conv](args, mods, buff, funs))
		return (0);
	if (mods.prec_spec == 1 || ft_strin(PRINTF_FLOAT, mods.conv))
		ft_printf_prec(mods, buff);
	i = 0;
	while (mods.flags[i])
	{
		if (!ft_strin(PRINTF_PASIVE_FLAGS, mods.flags[i]))
			funs[(int)mods.flags[i]](args, mods, buff);
		++i;
	}
	if (mods.width != 0)
		ft_printf_width(mods, buff);
	return (1);
}

static int	ft_printf_parse_mods(char **format, va_list *args,
			t_printf_buff *buff)
{
	t_printf_mods	mods;
	t_printf_buff	*new_node;
	int				ret;

	if (!(**format))
		return (0);
	ft_printf_parse_flags(format, &mods);
	ft_printf_parse_f_width(format, &mods);
	ft_printf_parce_prec(format, &mods);
	ft_printf_parce_length(format, &mods);
	if (!ft_printf_parce_conv(format, &mods))
		return (0);
	while (buff->next != NULL)
		buff = buff->next;
	new_node = ft_memalloc(sizeof(t_printf_buff *));
	new_node->next = NULL;
	buff->next = new_node;
	ret = ft_printf_exec(mods, args, new_node);
	ft_strdel(&(mods.flags));
	if (ret == 0)
		return (0);
	return (1);
}

static int	ft_printf_iter(char **format, va_list *args, t_printf_buff *buff)
{
	t_printf_buff	*new_node;
	size_t			size;

	while (**format != '\0')
	{
		if (ft_strin(PRINTF_MOD0, **format))
		{
			(*format)++;
			ft_printf_parse_mods(format, args, buff);
		}
		if (!ft_strin(PRINTF_MOD0, **format))
		{
			while (buff->next != NULL)
				buff = buff->next;
			new_node = ft_memalloc(sizeof(t_printf_buff *));
			new_node->next = NULL;
			buff->next = new_node;
			size = ft_strfdist(*format, PRINTF_MOD0);
			new_node->buff = ft_strndup(*format, size);
			(*format) += size;
		}
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	size_t			chars_printed;
	t_printf_buff	*buff;
	t_printf_buff	*prev_node;
	va_list			args;

	chars_printed = 0;
	buff = ft_memalloc(sizeof(t_printf_buff*));
	buff->next = NULL;
	buff->buff = NULL;
	va_start(args, format);
	ft_printf_iter((char **)&format, &args, buff);
	while (buff != NULL)
	{
		chars_printed += ft_putstr(buff->buff);
		ft_strdel(&(buff->buff));
		prev_node = buff;
		buff = buff->next;
		free(prev_node);
	}
	va_end(args);
	return ((int)chars_printed);
}
