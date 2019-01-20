/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:05:55 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/05 16:43:58 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_asgn(char **arr, char *str, char c, int w)
{
	int	i;

	while (*str)
	{
		if (*str != c)
		{
			i = 0;
			while (*str && *str != c)
				arr[w][i++] = *str++;
			arr[w][i] = '\0';
			++w;
		}
		else
			++str;
	}
	arr[w] = NULL;
}

static int	ft_memall(char **arr, char *str, char c, int i)
{
	int w;

	while (*str)
	{
		if (*str != c)
		{
			w = 1;
			while (*str && *str != c && ++w > 0)
				++str;
			arr[i] = (char *)malloc(sizeof(**arr) * w);
			if (arr[i++] == NULL)
				return (0);
		}
		else
			++str;
	}
	return (1);
}

static int	ft_cnt(char *str, char c, int w)
{
	while (*str)
		if (*str++ != c && (!*str || *str == c))
			++w;
	return (w);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**arr;
	int			w;

	if (s == NULL)
		return (NULL);
	w = ft_cnt((char*)s, c, 1);
	arr = (char **)malloc(sizeof(*arr) * w);
	if (arr == NULL)
		return (NULL);
	if (ft_memall(arr, (char*)s, c, 0) == 0)
		return (NULL);
	ft_asgn(arr, (char*)s, c, 0);
	return (arr);
}
