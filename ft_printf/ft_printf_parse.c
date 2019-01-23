/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_parse_flags(char **format, t_printf_mods *mods)
{
	int i;
	int n_of_flags;

	i = 0;
	n_of_flags = (int)ft_strlen(PRINTF_FLAGS);
	mods->flags = ft_strnew((size_t)n_of_flags);
	while (ft_is_included(PRINTF_FLAGS, **format))
	{
		if (i < n_of_flags && !ft_is_included(mods->flags, **format))
			mods->flags[i++] = **format;
		while (**format == *(*format + 1))
			(*format)++;
		(*format)++;
	}
}

void	ft_printf_parse_f_width(char **format, t_printf_mods *mods)
{
	int	width;

	mods->f_width = 0;
	if (**format == '0')
		return ;
	width = 0;
	while (**format >= '0' && **format <= '9')
	{
		width = width * 10 + **format - '0';
		(*format)++;
	}
	mods->f_width = width;
}

void	ft_printf_parce_prec(char **format, t_printf_mods *mods)
{
	int	precis;

	mods->prec_spec = 0;
	mods->prec = 0;
	if (**format != '.')
		return ;
	mods->prec_spec = 1;
	(*format)++;
	precis = 0;
	while (**format >= '0' && **format <= '9')
	{
		precis = precis * 10 + **format - '0';
		(*format)++;
	}
	mods->prec = precis;
}

void	ft_printf_parce_length(char **format, t_printf_mods *mods)
{
	int	i;

	mods->length = ft_strnew(2);
	if (!ft_is_included(PRINTF_LENGTH, **format))
		return ;
	i = 0;
	mods->length[i] = **format;
	++i;
	(*format)++;
	if (ft_is_included(PRINTF_DLENGTH, **format) && **format == *(*format - 1))
	{
		mods->length[i] = **format;
		(*format)++;
	}
}

int		ft_printf_parce_conv(char **format, t_printf_mods *mods)
{
	mods->conv = '\0';
	if (!ft_is_included(PRINTF_CONVS, **format))
	{
		ft_strdel(&(mods->length));
		ft_strdel(&(mods->flags));
		return (0);
	}
	mods->conv = **format;
	(*format)++;
	if (mods->prec_spec == 0 && (ft_is_included(PRINTF_CONVS_UNS, mods->conv)
	|| ft_is_included(PRINTF_CONVS_SN, mods->conv)))
		mods->prec = 1;
	else if (mods->prec_spec == 0 && mods->conv == 'f')
		mods->prec = 6;
	return (1);
}
