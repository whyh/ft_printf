/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:23:34 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/19 22:34:14 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ret;
	unsigned char	*str;

	ret = NULL;
	str = (unsigned char *)s;
	c = (unsigned char)c;
	while (*str)
	{
		if (*str == c)
			ret = (char *)str;
		++str;
	}
	if (*str == c)
		ret = (char*)str;
	return (ret);
}
