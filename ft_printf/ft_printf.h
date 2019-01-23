/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:03:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:22 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"
# include "ft_printf_typedefs.h"

int		ft_printf(const char *format, ...);
void	ft_printf_parse_flags(char **format, t_printf_mods *mods);
void	ft_printf_parse_f_width(char **format, t_printf_mods *mods);
void	ft_printf_parce_prec(char **format, t_printf_mods *mods);
void	ft_printf_parce_length(char **format, t_printf_mods *mods);
int		ft_printf_parce_conv(char **format, t_printf_mods *mods);
void	ft_printf_fill_funs(t_printf_funs **funs);
int		ft_printf_di(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_o(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_u(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_x(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_cap_x(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_c(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_s(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_p(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_f(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_mod0(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_hash(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_plus(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_blank(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_zero(va_list *args, t_printf_mods mods, t_printf_buff *buff);
void	ft_printf_prec(t_printf_mods mods, t_printf_buff *buff);
void	ft_printf_width(t_printf_mods mods, t_printf_buff *buff);

#endif
