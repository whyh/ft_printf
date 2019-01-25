/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:35:38 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/19 22:19:15 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*s;

	if (s2 == NULL)
		return (s1);
	s = s1;
	while (*s)
		++s;
	while (*s2)
		*s++ = *s2++;
	*s = '\0';
	return (s1);
}

wchar_t	*ft_wstrcat(wchar_t *s1, const wchar_t *s2)
{
	wchar_t	*s;

	if (s2 == NULL)
		return (s1);
	s = s1;
	while (*s)
		++s;
	while (*s2)
		*s++ = *s2++;
	*s = '\0';
	return (s1);
}
