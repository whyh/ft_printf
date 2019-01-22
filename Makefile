# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 20:30:28 by dderevyn          #+#    #+#              #
#    Updated: 2019/01/21 20:30:33 by dderevyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

LIBFT_PATH = libft/
LIBFT_INCS = libft.h
LIBFT_SRCS = 	ft_atoi.c\
				ft_atoibase.c\
				ft_bzero.c\
				ft_find_distance_to_char.c\
				ft_get_next_line.c\
				ft_intiteri.c\
				ft_is_included.c\
				ft_is_whitespace.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoabase.c\
				ft_linelen.c\
				ft_linetrim.c\
				ft_lstadd.c\
				ft_lstdel.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_memalloc.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memdel.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar.c\
				ft_putchar_fd.c\
				ft_putendl.c\
				ft_putendl_fd.c\
				ft_putnbr.c\
				ft_putnbr_fd.c\
				ft_putstr.c\
				ft_putstr_fd.c\
				ft_strcat.c\
				ft_strchr.c\
				ft_strclr.c\
				ft_strcmp.c\
				ft_strcpy.c\
				ft_strdel.c\
				ft_strdup.c\
				ft_strequ.c\
				ft_strinject.c\
				ft_striter.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlen.c\
				ft_strmap.c\
				ft_strmapi.c\
				ft_strncat.c\
				ft_strncmp.c\
				ft_strncpy.c\
				ft_strndup.c\
				ft_strnequ.c\
				ft_strnew.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strsplit.c\
				ft_strstr.c\
				ft_strsub.c\
				ft_strtrim.c\
				ft_tolower.c\
				ft_toupper.c

PRINTF_PATH = ft_printf/
PRINTF_INCS = ft_printf.h
PRINTF_SRCS =	ft_printf.c\
				ft_printf_convs_cspf.c\
				ft_printf_convs_diouxx.c\
				ft_printf_fill_funs.c\
				ft_printf_flags_base.c\
				ft_printf_parse.c\
				ft_printf_prec_f_width.c

INCS = $(addprefix $(LIBFT_PATH),$(LIBFT_INCS))
INCS += $(addprefix $(PRINTF_PATH),$(PRINTF_INCS))

SRCS = $(addprefix $(LIBFT_PATH),$(LIBFT_SRCS))
SRCS += $(addprefix $(PRINTF_PATH),$(PRINTF_SRCS))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS) -I.$(INCS)
	ar rc libft.a *.o
	ranlib $(NAME)

libf:
	cd libft && make

run:
	$(CC) $(CFLAGS) main.c -Llibftprintf -o  && ./a.out

norm:
	norminette $(SRCS) $(INCS) && cd libft && make norm

clean:
	$(RM) $(OBJS) && cd libft && make clean

fclean: clean
	$(RM) $(NAME) && cd libft && make fclean

re: fclean all

.Phony: fclean all clean re norm run
