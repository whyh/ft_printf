/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:20:19 by dderevyn          #+#    #+#             */
/*   Updated: 2018/10/31 17:49:05 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*str;

	if (!(str = (wchar_t *)malloc((size + 1) * sizeof(wchar_t))))
		return (NULL);
	ft_memset(str, L'\0', size + 1);
	return (str);
}
