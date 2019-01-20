/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:31:31 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/16 14:45:04 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	static_ft_fdset(char *set)
{
	int	i;
	int	i2;

	i = 0;
	while (set[i])
	{
		if (!ft_isalnum((int)set[i]))
			return (1);
		++i;
	}
	i = 0;
	while (set[i])
	{
		i2 = i + 1;
		while (set[i2])
		{
			if (set[i] == set[i2])
				return (1);
			++i2;
		}
		++i;
	}
	if (i < 2)
		return (1);
	return (0);
}

int			ft_atoibase(char *set, char *str)
{
	long long int	nbr;
	int				base;
	int				sign;

	if (!set || !str || static_ft_fdset(set))
		return (0);
	base = (int)ft_strlen(set);
	sign = 1;
	nbr = 0;
	while (ft_is_whitespace((int)*str))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str && ft_is_included(set, *str))
	{
		nbr = nbr * base + *str - '0';
		++str;
	}
	return ((int)(sign * nbr));
}
