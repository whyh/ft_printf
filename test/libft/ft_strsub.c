/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:53:03 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/01 15:11:24 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*f;

	if (s == NULL)
		return (NULL);
	f = ft_strnew(len);
	if (f == NULL)
		return (NULL);
	f = ft_strncpy(f, s + start, len);
	if (f == NULL)
		return (NULL);
	return (f);
}
