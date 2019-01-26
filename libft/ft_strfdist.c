/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfdist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strfdist(char *str, char *obj)
{
	size_t	distance;
	int		i;

	distance = 0;
	while (str[distance])
	{
		i = 0;
		while (obj[i])
		{
			if (str[distance] == obj[i])
				return (distance);
			++i;
		}
		++distance;
	}
	return (distance);
}

size_t	ft_strfdistc(char *str, char obj)
{
	size_t	distance;

	distance = 0;
	while (str[distance])
	{
		if (str[distance] == obj)
			return (distance);
		++distance;
	}
	return (distance);
}
