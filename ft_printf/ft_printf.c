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

int	ft_printf(const char *format, ...)
{
	size_t 			chars_printed;
	t_printf_buff	*buff;
	va_list			args;

	chars_printed = 0;
	buff = ft_memalloc(sizeof(t_printf_buff*));
	buff->next = NULL;
	buff->buff = NULL;
	va_start(args, format);
	ft_printf_iter((char **)&format, &args, buff);
	while (buff != NULL)
	{
		chars_printed += ft_putstr(buff->buff);//unicode putstr
		buff = buff->next;
	}
	//del list
	va_end(args);
	return ((int)chars_printed);
}

int ft_printf_iter(char **format, va_list *args, t_printf_buff *buff)
{
	while (**format != '\0')
	{
		if (**format == '%' && *(*format + 1) != '%')
		{
			(*format)++;
			if (!ft_printf_parse_mods(format, args, buff))
				return (0);
		}
		if (**format != '%')
			ft_printf_save_to_buff(format, buff);
	}
	return (1);
}

void	ft_printf_save_to_buff(char **format, t_printf_buff *buff)
{
	t_printf_buff	*new_node;
	size_t			size;

	while (buff->next != NULL)
		buff = buff->next;
	new_node = ft_memalloc(sizeof(t_printf_buff *));
	new_node->next = NULL;
	buff->next = new_node;
	if (**format == '%')
	{
		new_node->buff = ft_strdup("%");
		(*format)++;
		return ;
	}
	size = ft_find_distance_to_char(*format, '%');
	new_node->buff = ft_strndup(*format, size);
	(*format) += size;
}

int ft_printf_parse_mods(char **format, va_list *args, t_printf_buff *buff)
{
	t_printf_mods	mods;
	t_printf_buff	*new_node;

	if (**format == '\0')
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
	if (!(ft_printf_exec(mods, args, new_node)))
		return (0);
	return (1);
}

int ft_printf_exec(t_printf_mods mods, va_list *args, t_printf_buff *buff)
{
	static t_printf_funs	*funs = NULL;
	int 					i;

	if (!funs)
	{
		funs = ft_memalloc(sizeof(t_printf_funs *) * 256);
		ft_printf_fill_flags(funs);
		ft_printf_fill_convs(funs);
	}
	if (!funs[(int)mods.conv](args, mods, buff)) // check for '\0' if so remove return in func upper
		return (0);
	if (mods.prec_spec == 1 || mods.conv == 'f')
		if (!(ft_printf_prec(mods, buff)))
			return (0);
	i = 0;
	while (mods.flags[i])
	{
		if (funs[(int)mods.flags[i]])
			if (!(funs[(int)mods.flags[i]](args, mods, buff)))
				return (0);
		++i;
	}
	if (mods.f_width != 0)
		ft_printf_f_width(mods, buff);
	return (1);
}