/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:21:06 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/05 18:01:54 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
		new_node->next = NULL;
		return (new_node);
	}
	new_node->content = (void*)ft_memalloc(content_size);
	ft_memcpy(new_node->content, content, content_size);
	if (new_node->content == NULL)
		return (NULL);
	new_node->content_size = content_size;
	new_node->next = NULL;
	return (new_node);
}
