/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:21:37 by dderevyn          #+#    #+#             */
/*   Updated: 2018/10/30 11:48:31 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isupper(int c)
{
	return (64 < c && c < 91 ? 1 : 0);
}

static int	islower(int c)
{
	return (96 < c && c < 123 ? 1 : 0);
}

int			ft_isalpha(int c)
{
	return (isupper(c) || islower(c) ? 1 : 0);
}
