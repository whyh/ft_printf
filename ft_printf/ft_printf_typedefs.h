/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_typedefs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPEDEFS_H
# define FT_PRINTF_TYPEDEFS_H

# define PRINTF_FLAGS "+- 0#"
# define PRINTF_LENGTH "lhL"
# define PRINTF_DLENGTH "lh"
# define PRINTF_SN "di"
# define PRINTF_FLOAT "fF"
# define PRINTF_STR "s"
# define PRINTF_PTR "p"
# define PRINTF_CHR "c"
# define PRINTF_NDEC "oxX"
# define PRINTF_USN "u"
# define PRINTF_MOD0 "%"

typedef struct				s_printf_buff
{
	char					*buff;
	struct s_printf_buff	*next;
}							t_printf_buff;

typedef struct				s_printf_mods
{
	char					conv;
	int						width;
	int						prec;
	int						prec_spec : 2;
	char					*length;
	char					*flags;
}							t_printf_mods;

typedef int					(*t_printf_funs)(va_list *args, t_printf_mods mods,
							t_printf_buff *buff);

#endif
