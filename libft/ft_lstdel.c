/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:16:26 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/06 15:23:12 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*c;

	while ((*alst)->next != NULL)
	{
		c = (*alst)->next;
		ft_lstdelone(&(*alst), del);
		*alst = c;
	}
	ft_lstdelone(&(*alst), del);
	*alst = NULL;
}
