/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:23:34 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/06 20:01:06 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char c)
{
	const unsigned char	*ustr;
	unsigned char		uc;
	size_t				i;

	ustr = (UC*)str;
	uc = (UC)c;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == c)
			return ((char*)(&(str[i])));
		--i;
	}
	if (str[i] == c)
		return ((char*)(&(str[i])));
	return (NULL);
}
