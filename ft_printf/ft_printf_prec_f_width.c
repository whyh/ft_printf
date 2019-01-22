/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prec_f_width.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_prec(t_printf_mods mods, t_printf_buff *buff)
{
	if (ft_is_included(PRINTF_CONVS_SN, mods.conv)
	|| ft_is_included(PRINTF_CONVS_UNS, mods.conv))
	{
		ft_printf_prec_sn_uns(mods, buff);
		return (1);
	}
	if (mods.conv == 'f')
	{
		ft_printf_prec_float(mods, buff);
		return (1);
	}
	if (mods.conv == 's')
	{
		ft_printf_prec_str(mods, buff);
		return (1);
	}
	return (0);
}

void	ft_printf_prec_sn_uns(t_printf_mods mods, t_printf_buff *buff)
{
	size_t	length;
	char	*head;
	char	*tmp;

	if (mods.prec == 0)
	{
		if (buff->buff[0] == '0' && buff->buff[1] == '\0')
			buff->buff[0] = '\0';
		return ;
	}
	length = mods.prec - ft_strlen(buff->buff);
	if (length <= 0)
		return ;
	head = ft_strnew(length);
	head = ft_memset(head, '0', length);
	tmp = ft_strjoin(head, buff->buff);
	ft_strdel(&head);
	ft_strdel(&(buff->buff));
	buff->buff = tmp;
}

void	ft_printf_prec_str(t_printf_mods mods, t_printf_buff *buff)
{
	char	*tmp;

	if (mods.prec >= (int)ft_strlen(buff->buff))
		return ;
	tmp = ft_strnew(mods.prec);
	tmp = ft_strncpy(tmp, buff->buff, mods.prec);
//	ft_strdel(&(buff->buff));
	buff->buff = tmp;
}

void	ft_printf_prec_float(t_printf_mods mods, t_printf_buff *buff)
{
	char	*tmp;
	char	*tmp2;
	int		i;
	int		length;

	if (mods.prec_spec == 0)
		mods.prec = 6;
	tmp = ft_strchr(buff->buff, '.');
	length = (int)ft_strlen(tmp) - 1;
	if (length < mods.prec)
	{
		tmp = ft_strnew((size_t)(mods.prec - length));
		ft_memset(tmp, '0', (size_t)(mods.prec - length));
		tmp2 = ft_strjoin(buff->buff, tmp);
		ft_strdel(&(buff->buff));
		ft_strdel(&tmp);
		buff->buff = tmp2;
	}
	while (length > mods.prec)
	{
		i = 1;
		if (tmp[length] > '5')
		{
			tmp[length - i]++;
			while (tmp[length - i] >= '9' && length - i > mods.prec)
			{
				tmp[length - i] = '\0';
				++i;
			}
		}
		tmp[length] = '\0';
		length -= i;
	}
}

void		ft_printf_f_width(t_printf_mods mods, t_printf_buff *buff)
{
	int		length;
	char	*head;
	char	*tmp;

	length = (int)ft_strlen(buff->buff);
	if (ft_is_included(mods.flags, '0') && mods.conv != 'f'
	&& !ft_is_included(PRINTF_CONVS_UNS, mods.conv)
	&& !ft_is_included(PRINTF_CONVS_SN, mods.conv))
		return ;//handle error
	if (length >= mods.f_width)
		return ;
	head = ft_strnew((size_t)mods.f_width - length);
	if (mods.prec == 1 && ft_is_included(mods.flags, '0')
	&& !ft_is_included(mods.flags, '-'))
		head = ft_memset(head, '0', (size_t)(mods.f_width - length));
	else
		head = ft_memset(head, ' ', (size_t)(mods.f_width - length));
	if (ft_is_included(mods.flags, '-'))
		tmp = ft_strjoin(buff->buff, head);
	else
		tmp = ft_strjoin(head, buff->buff);
	ft_strdel(&head);
//	ft_strdel(&(buff->buff));
	buff->buff = tmp;
}