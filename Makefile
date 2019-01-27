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

OBJS_DIR = .libftprintf_objects
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

LIBFT_PATH = libft/
LIBFT_INCS =	libft.h\
				libft_typedefs.h\
				ft_gnl_typedefs.h
LIBFT_SRCS = 	ft_atoi.c\
				ft_atoibase.c\
				ft_bzero.c\
				ft_strfdist.c\
				ft_gnl.c\
				ft_strin.c\
				ft_iswhitespace.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoabase.c\
				ft_linelen.c\
				ft_linetrim.c\
				ft_memalloc.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memdel.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar.c\
				ft_putnbr.c\
				ft_putstr.c\
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
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlen.c\
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
LIBFT_OBJS = $(LIBFT_SRCS:%.c=$(LIBFT_OBJS_DIR)/%.o)
LIBFT_OBJS_DIR = $(OBJS_DIR)

PRINTF_PATH = ft_printf/
PRINTF_INCS =	ft_printf.h\
				ft_printf_typedefs.h
PRINTF_SRCS =	ft_printf.c\
				ft_printf_cspf.c\
				ft_printf_diouxx.c\
				ft_printf_fill_funs.c\
				ft_printf_hash_zero_blank_plus.c\
				ft_printf_parse.c\
				ft_printf_prec.c\
				ft_printf_width.c\
				ft_printf_mod0_b_cap_udo.c\
				ft_printf_0_base.c\
				ft_printf_lhllhhl.c\
				ft_printf_zjt.c\
				ft_printf_r.c\
				ft_printf_unicode.c\
				ft_printf_parce_funs.c\
				ft_printf_collor.c
PRINTF_OBJS = $(PRINTF_SRCS:%.c=$(PRINTF_OBJS_DIR)/%.o)
PRINTF_OBJS_DIR = $(OBJS_DIR)

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(PRINTF_OBJS)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

$(LIBFT_OBJS_DIR)/%.o: $(LIBFT_PATH)%.c
	@mkdir -p $(LIBFT_OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< $(addprefix -I.,$(addprefix $(LIBFT_PATH),$(LIBFT_INCS))) -o $@

$(PRINTF_OBJS_DIR)/%.o: $(PRINTF_PATH)%.c
	@mkdir -p $(LIBFT_OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< $(addprefix -I.,$(addprefix $(PRINTF_PATH),$(PRINTF_INCS))) -o $@

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	@norminette $(addprefix $(LIBFT_PATH),$(LIBFT_SRCS)) \
	$(addprefix $(LIBFT_PATH),$(LIBFT_INCS)) \
	$(addprefix $(PRINTF_PATH),$(PRINTF_SRCS)) \
	$(addprefix $(PRINTF_PATH),$(PRINTF_INCS))

run:
	@$(CC) $(CFLAGS) main.c libftprintf.a | cat -e
	@./a.out || true
	@$(RM) ./a.out

run_warn:
	@$(CC) main.c libftprintf.a
	@./a.out || true
	@$(RM) ./a.out

test: rmt
	@mkdir -p test
	@cp -rf $(LIBFT_PATH) test/$(LIBFT_PATH)
	@cp -rf $(PRINTF_PATH) test/$(PRINTF_PATH)
	@cp -rf author test/author
	@cp -rf Makefile test/Makefile
	@cd test && pwd | cut -c 17-44

rmt:
	@$(RM) test

.PHONY: all clean fclean re norm run run_warn test rmt
