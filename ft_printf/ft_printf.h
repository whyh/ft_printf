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

#include <stdarg.h>
#include <stdint.h>
#include "../libft/libft.h"

# define PRINTF_FLAGS "+- 0#"
# define PRINTF_CONVS "%cspdifouxX"
# define PRINTF_CONVS_SN "di"
# define PRINTF_CONVS_UNS "%ouxX"
# define PRINTF_LENGTH "lhL"
# define PRINTF_DLENGTH "lh"


typedef struct				s_printf_buff
{
	char					*buff;
	struct s_printf_buff	*next;
}							t_printf_buff;

typedef struct	s_printf_mods
{
	char		conv;
	int			f_width;
	int			prec;
	int 		prec_spec : 2;
	char		*length;
	char 		*flags;
}				t_printf_mods;

typedef int (*t_printf_funs)(va_list *args, t_printf_mods mods, t_printf_buff *buff);
//2nd array ?

int		ft_printf(const char *format, ...);
void	ft_printf_save_to_buff(char **format, t_printf_buff *buff);
int 	ft_printf_iter(char **format, va_list *args, t_printf_buff *buff);
int 	ft_printf_parse_mods(char **format, va_list *args, t_printf_buff *buff);
void	ft_printf_parse_flags(char **format, t_printf_mods *mods);
void	ft_printf_parse_f_width(char **format, t_printf_mods *mods);
void	ft_printf_parce_prec(char **format, t_printf_mods *mods);
void	ft_printf_parce_length(char **format, t_printf_mods *mods);
int		ft_printf_parce_conv(char **format, t_printf_mods *mods);
int 	ft_printf_exec(t_printf_mods mods, va_list *args, t_printf_buff *buff);
void	ft_printf_fill_convs(t_printf_funs *funs);
int		ft_printf_convs_di(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_conv_o(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_conv_u(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_conv_x(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_conv_cap_x(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_conv_c(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_conv_s(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_conv_p(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_conv_f(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_conv_nothing(va_list *args, t_printf_mods mods, t_printf_buff *buff);
void	ft_printf_fill_flags(t_printf_funs *funs);
int		ft_printf_flag_hash(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_flag_plus(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_flag_blank(va_list *args, t_printf_mods mods, t_printf_buff *buff);
int		ft_printf_prec(t_printf_mods mods, t_printf_buff *buff);
void	ft_printf_prec_sn_uns(t_printf_mods mods, t_printf_buff *buff);
void	ft_printf_prec_str(t_printf_mods mods, t_printf_buff *buff);
void	ft_printf_prec_float(t_printf_mods mods, t_printf_buff *buff);
void	ft_printf_f_width(t_printf_mods mods, t_printf_buff *buff);
void	ft_printf_split_float(long double arg, long long a_args[4]);

#endif
