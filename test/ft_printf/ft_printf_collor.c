/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_collor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printf_getmod2(char *mod)
{
	if (ft_strequ(mod, "[greenb"))
		return (ft_strdup("\033[42m"));
	if (ft_strequ(mod, "[yellowb"))
		return (ft_strdup("\033[43m"));
	if (ft_strequ(mod, "[blueb"))
		return (ft_strdup("\033[44m"));
	if (ft_strequ(mod, "[magentab"))
		return (ft_strdup("\033[45m"));
	if (ft_strequ(mod, "[cyanb"))
		return (ft_strdup("\033[46m"));
	if (ft_strequ(mod, "[whiteb"))
		return (ft_strdup("\033[47m"));
	return (NULL);
}

static char	*ft_printf_getmod1(char *mod)
{
	if (ft_strequ(mod, "]~"))
		return (ft_strdup("\033[0m"));
	if (ft_strequ(mod, "[bold"))
		return (ft_strdup("\033[1m"));
	if (ft_strequ(mod, "[black"))
		return (ft_strdup("\033[30m"));
	if (ft_strequ(mod, "[red"))
		return (ft_strdup("\033[31m"));
	if (ft_strequ(mod, "[green"))
		return (ft_strdup("\033[32m"));
	if (ft_strequ(mod, "[yellow"))
		return (ft_strdup("\033[33m"));
	if (ft_strequ(mod, "[blue"))
		return (ft_strdup("\033[34m"));
	if (ft_strequ(mod, "[magenta"))
		return (ft_strdup("\033[35m"));
	if (ft_strequ(mod, "[cyan"))
		return (ft_strdup("\033[36m"));
	if (ft_strequ(mod, "[white"))
		return (ft_strdup("\033[37m"));
	if (ft_strequ(mod, "[blackb"))
		return (ft_strdup("\033[40m"));
	if (ft_strequ(mod, "[redb"))
		return (ft_strdup("\033[41m"));
	return (ft_printf_getmod2(mod));
}

static int	ft_printf_findmod(char **mod)
{
	char	*tmp;

	if (!ft_strequ(*mod, "]~") && !ft_strequ(*mod, "[bold")
	&& !ft_strequ(*mod, "[black") && !ft_strequ(*mod, "[blackb")
	&& !ft_strequ(*mod, "[red") && !ft_strequ(*mod, "[redb")
	&& !ft_strequ(*mod, "[green") && !ft_strequ(*mod, "[greenb")
	&& !ft_strequ(*mod, "[yellow") && !ft_strequ(*mod, "[yellowb")
	&& !ft_strequ(*mod, "[blue") && !ft_strequ(*mod, "[blueb")
	&& !ft_strequ(*mod, "[magenta") && !ft_strequ(*mod, "[magentab")
	&& !ft_strequ(*mod, "[cyan") && !ft_strequ(*mod, "[cyanb")
	&& !ft_strequ(*mod, "[white") && !ft_strequ(*mod, "[whiteb"))
		return (0);
	tmp = ft_printf_getmod1(*mod);
	ft_strdel(mod);
	*mod = tmp;
	return (1);
}

void		ft_printf_collor(t_printf_buff *node, int i, char *tail,
			char *mod)
{
	char	*head;
	size_t	i2;

	while (node->buff[++i]
	&& (ft_strin(&(node->buff[i]), '[') || ft_strin(&(node->buff[i]), ']')))
	{
		while (node->buff[i] && node->buff[i] != ']' && node->buff[i] != '[')
			++i;
		head = ft_strndup(node->buff, (size_t)i);
		i2 = (size_t)i + 1;
		while ((node->buff[i2] >= 'a' && node->buff[i2] <= 'z')
		|| node->buff[i2] == '~')
			++i2;
		tail = ft_strdup(&(node->buff[i2]));
		mod = ft_strndup(&(node->buff[i]), i2 - i);
		if (ft_printf_findmod(&mod))
		{
			ft_strinject(&head, mod, (size_t)i);
			ft_strdel(&(node->buff));
			node->buff = ft_strjoin(head, tail);
		}
		ft_strdel(&mod);
		ft_strdel(&head);
		ft_strdel(&tail);
	}
}
