/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:17:43 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/26 16:22:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}

wchar_t	*ft_wstrjoin(wchar_t *s1, wchar_t *s2)
{
	wchar_t	*str;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = ft_wstrlen(s1) + ft_wstrlen(s2);
	if (!(str = (wchar_t *)malloc((i + 1) * sizeof(wchar_t))))
		return (NULL);
	ft_wstrcpy(str, s1);
	ft_wstrcat(str, s2);
	return (str);
}
