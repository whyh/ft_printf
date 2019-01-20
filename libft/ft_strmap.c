/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:46:26 by dderevyn          #+#    #+#             */
/*   Updated: 2018/10/31 18:22:15 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		++i;
	res = (char *)malloc((++i) * sizeof(*res));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (*s)
		res[i++] = (*f)(*s++);
	res[i] = '\0';
	return (res);
}
