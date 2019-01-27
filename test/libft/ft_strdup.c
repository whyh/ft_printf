/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:25:16 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/28 19:30:17 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if (!(s2 = ft_strnew(ft_strlen(s1))))
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}

wchar_t	*ft_wstrdup(const wchar_t *s1)
{
	wchar_t	*s2;

	if (!(s2 = ft_wstrnew(ft_wstrlen(s1))))
		return (NULL);
	s2 = ft_wstrcpy(s2, s1);
	return (s2);
}
