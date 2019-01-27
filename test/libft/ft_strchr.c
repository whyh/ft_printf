/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:54:19 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/19 22:28:09 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;

	c = (unsigned char)c;
	str = (unsigned char *)s;
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		++str;
	}
	if (*str == c)
		return ((char *)str);
	return (NULL);
}
