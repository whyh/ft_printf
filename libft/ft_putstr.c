/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:14:10 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/16 14:33:21 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr(char const *s)
{
	size_t	length;

	if (s == NULL)
		return (0);
	length = ft_strlen(s);
	write(1, s, length);
	return (length);
}
