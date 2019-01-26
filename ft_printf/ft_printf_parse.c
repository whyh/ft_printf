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

void	ft_printf_parse_f_width(char **format, t_printf_mods *mods,
		va_list *args)
{
	int	width;

	(void)args;
	mods->width = 0;
	if (**format == '0')
		return ;
	if (**format == '*')
		ft_printf_get_asterix(mods, args, "width", format);
	if (ft_isdigit(**format))
	{
		width = 0;
		while (ft_isdigit(**format))
		{
			width = width * 10 + **format - '0';
			(*format)++;
		}
		mods->width = width;
	}
	if (**format == '*')
		ft_printf_get_asterix(mods, args, "width", format);
}

void	ft_printf_parce_prec(char **format, t_printf_mods *mods, va_list *args)
{
	int	prec;

	(void)args;
	mods->prec_spec = 0;
	mods->prec = 0;
	if (**format != '.')
		return ;
	mods->prec_spec = 1;
	(*format)++;
	if (**format == '*')
		ft_printf_get_asterix(mods, args, "prec", format);
	if (ft_isdigit(**format))
	{
		prec = 0;
		while (ft_isdigit(**format))
		{
			prec = prec * 10 + **format - '0';
			(*format)++;
		}
		mods->prec = prec;
	}
	if (**format == '*')
		ft_printf_get_asterix(mods, args, "prec", format);
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
	while (ft_strin(PRINTF_LENGTH2, **format)
	|| ft_strin(PRINTF_LENGTH1, **format))
		(*format)++;
}

int		ft_printf_parce_conv(char **format, t_printf_mods *mods)
{
	mods->conv = '\0';
	if (!ft_strin(PRINTF_SN, **format) && !ft_strin(PRINTF_USN, **format)
	&& !ft_strin(PRINTF_CHR, **format) && !ft_strin(PRINTF_NDEC, **format)
	&& !ft_strin(PRINTF_FLOAT, **format) && !ft_strin(PRINTF_PTR, **format)
	&& !ft_strin(PRINTF_STR, **format))
	{
		mods->conv = PRINTF_MOD0[0];
		mods->mod0 = **format;
	}
	else
		mods->conv = **format;
	(*format)++;
	if (mods->length == 'l' && ft_strin(PRINTF_CAPL, mods->conv))
	{
		mods->conv = (char)ft_toupper(mods->conv);
		mods->length = '\0';
	}
	return (1);
}
