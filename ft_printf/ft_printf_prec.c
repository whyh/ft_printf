/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_prec_sn_usn_p_ndec(t_printf_mods mods,
		t_printf_buff *buff)
{
	int		length;
	char	*head;
	int		i;

	if (mods.prec == 0 && !(i = 0))
	{
		if (ft_strin(PRINTF_PTR, mods.conv))
			i = 2;
		if (buff->buff[i] == '0' && buff->buff[i + 1] == '\0')
			buff->buff[i] = '\0';
		return ;
	}
	length = mods.prec - (int)ft_strlen(buff->buff);
	i = 0;
	if (mods.conv == 'p' && (i = 2))
		length += 2;
	if (buff->buff[0] == '-' && (i = 1))
		++length;
	if (length <= 0)
		return ;
	head = ft_strnew((size_t)length);
	head = ft_memset(head, '0', (size_t)length);
	ft_strinject(&(buff->buff), head, (size_t)i);
	ft_strdel(&head);
}

static void	ft_printf_prec_str(t_printf_mods mods, t_printf_buff *buff)
{
	char	*tmp;

	if (mods.prec >= (int)ft_strlen(buff->buff))
		return ;
	tmp = ft_strnew((size_t)mods.prec);
	tmp = ft_strncpy(tmp, buff->buff, (size_t)mods.prec);
	ft_strdel(&(buff->buff));
	buff->buff = tmp;
}

static void	ft_printf_prec_float_fix(t_printf_buff *buff, t_printf_mods mods,
			int length, int size)
{
	int i;
	int mod;

	mod = 0;
	while (length > mods.prec - 1)
	{
		if (buff->buff[size] > '5')
		{
			i = 1;
			while (buff->buff[size - i] == '9' || buff->buff[size - i] == '.')
				if (buff->buff[size - i++] == '9')
					buff->buff[size - i + 1] = '0';
			if (size - i >= 0 && buff->buff[size - i] != '-')
				buff->buff[size - i]++;
			else if (buff->buff[size - i] == '-' && (mod += 1))
				ft_strinject(&(buff->buff), "1", 1);
			else if ((mod += 1))
				ft_strinject(&(buff->buff), "1", 0);
		}
		buff->buff[size] = '\0';
		--size;
		--length;
	}
	if (mods.prec == 0)
		buff->buff[size + mod] = '\0';
}

static void	ft_printf_prec_float(t_printf_mods mods, t_printf_buff *buff)
{
	char	*tmp;
	char	*tmp2;
	int		length;
	int		size;

	tmp = ft_strchr(buff->buff, '.');
	if (tmp != NULL)
		length = (int)ft_strlen(tmp + 1) - 1;
	else
		length = 0;
	if (length < mods.prec)
	{
		tmp = ft_strnew((size_t)(mods.prec - length));
		ft_memset(tmp, '0', (size_t)(mods.prec - length));
		tmp2 = ft_strjoin(buff->buff, tmp);
		ft_strdel(&(buff->buff));
		ft_strdel(&tmp);
		buff->buff = tmp2;
		return ;
	}
	size = (int)ft_strlen(buff->buff) - 1;
	ft_printf_prec_float_fix(buff, mods, length, size);
}

void		ft_printf_prec(t_printf_mods mods, t_printf_buff *buff)
{
	if (ft_strin(PRINTF_SN, mods.conv) || ft_strin(PRINTF_PTR, mods.conv)
	|| ft_strin(PRINTF_USN, mods.conv) || ft_strin(PRINTF_NDEC, mods.conv))
		ft_printf_prec_sn_usn_p_ndec(mods, buff);
	else if (ft_strin(PRINTF_FLOAT, mods.conv))
		ft_printf_prec_float(mods, buff);
	else if (ft_strin(PRINTF_STR, mods.conv))
		ft_printf_prec_str(mods, buff);
}
