/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:43:25 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/19 20:50:50 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*a;
	const char	*b;

	a = dst;
	b = src;
	c = (unsigned char)c;
	while (n-- > 0)
	{
		*a++ = *b;
		dst = a;
		if ((unsigned char)*b++ == c)
			return (dst);
	}
	return (NULL);
}
