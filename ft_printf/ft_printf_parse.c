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
	int	i;
	int	nb;

	i = 0;
	nb = (int)ft_strlen(PRINTF_FLAGS) + (int)ft_strlen(PRINTF_PASIVE_FLAGS);
	mods->flags = ft_strnew((size_t)nb);
	while (ft_strin(PRINTF_FLAGS, **format)
	|| ft_strin(PRINTF_PASIVE_FLAGS, **format))
	{
		if (i < nb && !ft_strin(mods->flags, **format))
		{
			mods->flags[i] = **format;
			++i;
		}
		while (**format == *(*format + 1))
			(*format)++;
		(*format)++;
	}
}

void	ft_printf_parse_f_width(char **format, t_printf_mods *mods)
{
	int	width;

	mods->width = 0;
	if (**format == '0')
		return ;
	width = 0;
	while (ft_isdigit(**format))
	{
		width = width * 10 + **format - '0';
		(*format)++;
	}
	mods->width = width;
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
	while (ft_isdigit(**format))
	{
		precis = precis * 10 + **format - '0';
		(*format)++;
	}
	mods->prec = precis;
}

void	ft_printf_parce_length(char **format, t_printf_mods *mods)
{
	int	i;

	mods->length = 0;
	if (!ft_strin(PRINTF_LENGTH1, **format))
		return ;
	i = 0;
	mods->length = **format;
	++i;
	(*format)++;
	if (ft_strin(PRINTF_LENGTH2, **format) && **format == *(*format - 1))
	{
		mods->length += **format;
		(*format)++;
	}
}

int		ft_printf_parce_conv(char **format, t_printf_mods *mods)
{
	mods->conv = '\0';
	if (!ft_strin(PRINTF_SN, **format) && !ft_strin(PRINTF_USN, **format)
	&& !ft_strin(PRINTF_CHR, **format) && !ft_strin(PRINTF_NDEC, **format)
	&& !ft_strin(PRINTF_FLOAT, **format) && !ft_strin(PRINTF_PTR, **format)
	&& !ft_strin(PRINTF_MOD0, **format) && !ft_strin(PRINTF_STR, **format))
	{
		ft_strdel(&(mods->flags));
		return (0);
	}
	mods->conv = **format;
	(*format)++;
	return (1);
}
