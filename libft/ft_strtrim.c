/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:22:26 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/01 19:08:47 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*a;
	int		l;
	int		i;
	int		len;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		++i;
	l = i;
	while (s[l] != '\0')
		++l;
	while (l > i && (s[l - 1] == '\t' || s[l - 1] == '\n' || s[l - 1] == ' '))
		--l;
	len = l - i;
	a = (char *)malloc(sizeof(*a) * (len + 1));
	if (a == NULL)
		return (NULL);
	l = 0;
	while (l < len)
		a[l++] = s[i++];
	a[len] = '\0';
	return (a);
}
