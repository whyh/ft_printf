/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:10:22 by dderevyn          #+#    #+#             */
/*   Updated: 2018/11/27 18:56:02 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft_typedefs.h"
# include "ft_gnl_typedefs.h"

void	ft_putchar(char c);
size_t	ft_putstr(char const *s);
void	ft_putnbr(int n);
int		ft_atoi(const char *string);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s);
void	ft_putendl(char const *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_strsplit(char const *s, char c);
int		ft_atoibase(char *set, char *str);
void	ft_intiteri(int *arr, int length, void (*f)(int, int*));
int		ft_strin(char *str, char c);
int		ft_iswhitespace(int c);
size_t	ft_linetrim(char **str, size_t n);
size_t	ft_linelen(char *str);
size_t	ft_strfdist(char *str, char *obj);
char	*ft_itoabase_unsigned(char *set, unsigned long long nb);
char	*ft_itoabase(char *set, long long nb);
char	*ft_strndup(const char *s1, size_t size);
void	ft_strinject(char **src, char *string, size_t pos);
int		ft_gnl(int fd, char **line);
void	ft_wstrdel(wchar_t **as);
void	ft_wstrinject(wchar_t **src, wchar_t *string, size_t pos);
wchar_t	*ft_wstrndup(const wchar_t *s1, size_t size);
wchar_t	*ft_wstrnew(size_t size);
wchar_t	*ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t len);
wchar_t	*ft_wstrdup(const wchar_t *s1);
wchar_t	*ft_wstrcpy(wchar_t *dst, const wchar_t *src);
wchar_t	*ft_wstrjoin(wchar_t *s1, wchar_t *s2);
size_t	ft_wstrlen(const wchar_t *s);
wchar_t	*ft_wstrcat(wchar_t *s1, const wchar_t *s2);
size_t	ft_strfdistc(char *str, char obj);

#endif
