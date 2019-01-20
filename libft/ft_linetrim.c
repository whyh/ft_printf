/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linetrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:13:38 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/26 16:19:24 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_linetrim(char **str, size_t n)
{
	size_t	sln;
	char	*ret;

	if (str == NULL || *str == NULL)
		return (0);
	sln = ft_strlen(*str + n);
	if (!(ret = ft_strnew(sln)))
		return (0);
	ret = ft_strcpy(ret, *str + n);
	ft_strdel(str);
	*str = ret;
	return (sln);
}
