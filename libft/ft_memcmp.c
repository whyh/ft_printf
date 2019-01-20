/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:37:49 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/19 19:24:25 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*a1;
	const char	*a2;

	a1 = s1;
	a2 = s2;
	while (n-- > 0)
		if (*a1++ != *a2++)
			return ((unsigned char)*(a1 - 1) - (unsigned char)*(a2 - 1));
	return (0);
}
