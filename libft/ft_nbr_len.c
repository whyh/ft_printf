/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:57:30 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 19:07:19 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbr_len(long long nbr, size_t base)
{
	size_t	len;

	len = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		++len;
	}
	while (nbr / base > 0)
	{
		nbr = nbr / base;
		++len;
	}
	return (len);
}

size_t	ft_unbr_len(unsigned long long nbr, size_t base)
{
	size_t	len;

	len = 1;
	while (nbr / base > 0)
	{
		nbr = nbr / base;
		++len;
	}
	return (len);
}
