/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:54:39 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/27 18:41:01 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*cpy;
	t_list	*cpyhead;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(cpy = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	cpyhead = cpy;
	while (lst->next != NULL)
	{
		lst = lst->next;
		cpy->next = ft_lstnew(lst->content, lst->content_size);
		cpy = cpy->next;
	}
	if (!(node = ft_lstnew(f(cpyhead)->content, f(cpyhead)->content_size)))
		return (NULL);
	cpy = node;
	while (cpyhead->next != NULL)
	{
		cpyhead = cpyhead->next;
		node->next = ft_lstnew(f(cpyhead)->content, f(cpyhead)->content_size);
		node = node->next;
	}
	return (cpy);
}
