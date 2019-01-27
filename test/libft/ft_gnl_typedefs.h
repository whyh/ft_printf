/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_typedefs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:10:22 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/27 18:56:02 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_TYPEDEFS_H
# define FT_GNL_TYPEDEFS_H

# define GNL_BUFF_SIZE 80

typedef struct		s_fd
{
	int				fd;
	char			*content;
	struct s_fd		*next;
}					t_fd;

#endif
