/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:52:14 by dderevyn          #+#    #+#             */
/*   Updated: 2018/10/31 18:17:44 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	if (as == NULL || *as == NULL)
		return ;
	free(*as);
	*as = NULL;
}

void	ft_wstrdel(wchar_t **as)
{
	if (as == NULL || *as == NULL)
		return ;
	free(*as);
	*as = NULL;
}
