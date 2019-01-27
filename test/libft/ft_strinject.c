/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinject.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strinject(char **src, char *string, size_t pos)
{
	char	*head;
	char	*tail;
	char	*tmp;

	head = ft_strndup(*src, pos);
	tail = ft_strdup(&((*src)[pos]));
	ft_strdel(src);
	tmp = ft_strjoin(head, string);
	*src = ft_strjoin(tmp, tail);
	ft_strdel(&head);
	ft_strdel(&tail);
	ft_strdel(&tmp);
}

void	ft_wstrinject(wchar_t **src, wchar_t *string, size_t pos)
{
	wchar_t	*head;
	wchar_t	*tail;
	wchar_t	*tmp;

	head = ft_wstrndup(*src, pos);
	tail = ft_wstrdup(&((*src)[pos]));
	ft_wstrdel(src);
	tmp = ft_wstrjoin(head, string);
	*src = ft_wstrjoin(tmp, tail);
	ft_wstrdel(&head);
	ft_wstrdel(&tail);
	ft_wstrdel(&tmp);
}
