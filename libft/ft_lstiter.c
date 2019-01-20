/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:36:56 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/05 19:54:30 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*crnt;

	if (!lst)
		return ;
	crnt = lst;
	while (crnt->next != NULL)
	{
		f(crnt);
		crnt = crnt->next;
	}
	f(crnt);
}
