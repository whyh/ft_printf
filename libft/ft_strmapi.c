/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:09:20 by dderevyn          #+#    #+#             */
/*   Updated: 2018/10/31 18:22:37 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

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
	{
		res[i] = (*f)(i, *s++);
		++i;
	}
	res[i] = '\0';
	return (res);
}
