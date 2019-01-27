/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:26:17 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/27 16:55:27 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && --n > 0)
		if (*s1++ != *s2++)
			return ((unsigned char)*(s1 - 1) - (unsigned char)*(s2 - 1));
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
