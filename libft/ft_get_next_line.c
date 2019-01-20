/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:25:21 by dderevyn          #+#    #+#             */
/*   Updated: 2018/12/07 17:43:30 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		static_del(t_fd *node, t_fd **head)
{
	t_fd	*tmp;

	if (*head == node)
	{
		ft_strdel(&((*head)->content));
		(*head)->fd = -42;
		return (1);
	}
	tmp = *head;
	while (tmp->next != node)
		tmp = tmp->next;
	tmp->next = node->next;
	if (node->content)
		ft_strdel(&(node->content));
	ft_memdel((void**)&node);
	return (1);
}

static int		static_valid_n_pull(t_fd **head, char **line, int fd)
{
	size_t	ln;
	t_fd	*node;

	if (line != NULL && *line != NULL)
		*line = NULL;
	node = *head;
	while (node != NULL && node->fd != fd)
		node = node->next;
	if (node == NULL)
		return (-42);
	ln = ft_linelen(node->content);
	if (fd < 0 || !(*line = ft_strnew(ln)))
		return (-1);
	ft_strncpy(*line, node->content, ln);
	if (node->content[ln] == '\0' && static_del(node, head))
		return (-42);
	if (node->content[ln] == '\n' && node->content[ln + 1] == '\0')
	{
		static_del(node, head);
		return (1);
	}
	if (!(ft_linetrim(&(node->content), ln + 1)))
		return (-1);
	return (1);
}

static t_fd		*static_store(char *content, int fd, t_fd *fdl)
{
	t_fd	*node;

	if (content[0] == '\0')
		content[0] = '\n';
	if (!(node = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	if (!(node->content = ft_strdup(content)))
		return (NULL);
	node->fd = fd;
	node->next = fdl;
	return (node);
}

static int		gnl_part2(char **line, ssize_t rbl, char rbuf[])
{
	char	*wbuf;
	char	*tmpp;
	size_t	ln;

	if (rbl == -1)
		return (-1);
	rbuf[rbl] = '\0';
	ln = ft_linelen(rbuf);
	if (!(wbuf = ft_strnew(ln)))
		return (-1);
	ft_strncpy(wbuf, rbuf, ln);
	tmpp = NULL;
	if (!(tmpp = ft_strjoin(*line, wbuf)))
		return (-1);
	if (*line)
		ft_strdel(line);
	*line = tmpp;
	ft_strdel(&wbuf);
	return (-42);
}

int				ft_get_next_line(int fd, char **line)
{
	static t_fd	*fdl;
	char		rbuf[GNL_BUFF_SIZE + 1];
	ssize_t		rbl;
	int			retflag;
	size_t		ln;

	if ((retflag = static_valid_n_pull(&fdl, line, fd)) != -42)
		return (retflag);
	while ((rbl = read(fd, rbuf, GNL_BUFF_SIZE)))
	{
		if ((retflag = gnl_part2(line, rbl, rbuf)) != -42)
			return (retflag);
		if ((ssize_t)(ln = ft_linelen(rbuf)) != rbl)
		{
			if ((ssize_t)ln + 1 != rbl)
				if (!(fdl = static_store(rbuf + ln + 1, fd, fdl)))
					return (-1);
			if (*line == NULL)
				*line = ft_strnew(0);
			return (1);
		}
	}
	if (*line == NULL)
		*line = ft_strnew(0);
	return (**line != '\0' ? 1 : 0);
}
