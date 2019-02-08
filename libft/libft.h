/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:10:22 by dderevyn          #+#    #+#             */
/*   Updated: 2019/02/08 14:22:55 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "libft_typedefs.h"

long long	ft_atoibase(char *set, char *str);
char		*ft_itoabase(char *set, long long nbr);
char		*ft_uitoabase(char *set, unsigned long long nbr);
void		*ft_memalloc(size_t size);
int			ft_memcmp(const void *mem1, const void *mem2, size_t n);
void		ft_memdel(void **memptr);
void		*ft_memmove(void *memdst, const void *memsrc, long size);
void		*ft_memset(void *memptr, unsigned char c, size_t size);
size_t		ft_nbr_len(long long nbr, size_t base);
size_t		ft_unbr_len(unsigned long long nbr, size_t base);
char		*ft_strchr(const char *str, char c);
size_t		ft_strchr_i(const char *str, char c);
void		ft_strdel(char **ptr);
int			ft_strin(const char *str, char c);
char		*ft_strjoin(const char *src1, const char *src2);
size_t		ft_strlen(const char *str);
char		*ft_strncpy(char *dst, const char *src, long n);
char		*ft_strndup(const char *src, long n);
int			ft_strncmp(char const *str1, char const *str2, long n);
char		*ft_strnew(size_t size);
void		ft_strninject(char **dst, const char *src, long pos, long n);
char		*ft_strrchr(const char *str, char c);

#endif
