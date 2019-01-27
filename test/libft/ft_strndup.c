/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:25:16 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/28 19:30:17 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char	*s2;

	if (!(s2 = ft_strnew(size)))
		return (NULL);
	s2 = ft_strncpy(s2, s1, size);
	return (s2);
}

wchar_t	*ft_wstrndup(const wchar_t *s1, size_t size)
{
	wchar_t	*s2;

	if (!(s2 = ft_wstrnew(size)))
		return (NULL);
	s2 = ft_wstrncpy(s2, s1, size);
	return (s2);
}
