/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:00:08 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/19 22:40:25 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	static_ft_is_whitespace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' ||
	c == '\f' || c == '\r' || c == ' ');
}

int			ft_atoi(const char *str)
{
	long long int	nbr;
	int				sign;

	sign = 1;
	nbr = 0;
	while (static_ft_is_whitespace((int)*str))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((nbr > LLONG_MAX / 10 ||
		(nbr == LLONG_MAX / 10 && *str > '7')) && sign == 1)
			return (-1);
		if ((nbr > LLONG_MAX / 10 ||
		(nbr == LLONG_MAX / 10 && *str > '8')) && sign == -1)
			return (0);
		nbr = nbr * 10 + *str - '0';
		++str;
	}
	return (sign * nbr);
}
