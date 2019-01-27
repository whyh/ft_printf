/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:22:05 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/01 13:55:53 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*a;

	a = s;
	while (n-- > 0)
		if ((unsigned char)*a++ == (unsigned char)c)
			return ((void*)(a - 1));
	return (NULL);
}
