# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 16:17:42 by dderevyn          #+#    #+#              #
#    Updated: 2019/02/06 21:34:32 by dderevyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

INCS =	libft.h\
		libft_typedefs.h
SRCS = 	ft_atoibase.c\
		ft_itoabase.c\
		ft_memalloc.c\
		ft_memcmp.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_nbr_len.c\
		ft_strchr.c\
		ft_strdel.c\
		ft_strin.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strncpy.c\
		ft_strndup.c\
		ft_strncmp.c\
		ft_strnew.c\
		ft_strninject.c\
		ft_strrchr.c

OBJS_DIR = .libft_objects
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< $(addprefix -I.,$(INCS)) -o $@

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	@norminette $(SRCS) $(INCS)

.PHONY: all clean fclean re norm
