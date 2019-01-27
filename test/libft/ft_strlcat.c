/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:03:09 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/21 14:07:19 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t dlen;
	size_t len;
	size_t i;

	dlen = ft_strlen(dst);
	i = 0;
	if (dlen < n)
		len = dlen;
	else
		len = n;
	if (n != 0)
		--n;
	while (src[i] != '\0' && dlen < n)
	{
		dst[dlen] = src[i];
		++i;
		++dlen;
	}
	dst[dlen] = '\0';
	return (len + ft_strlen(src));
}
