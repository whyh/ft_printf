# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 16:17:42 by dderevyn          #+#    #+#              #
#    Updated: 2018/11/16 16:55:53 by dderevyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

NAMEA = $(NAME).a

$(NAMEA):
	clang -Wall -Wextra -Werror -c *.c -I.libft.h
	ar rc $(NAMEA) *.o
	ranlib $(NAMEA)

all: $(NAMEA)

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -rf $(NAMEA)

re: fclean all

.PHONY: re all clean fclean $(NAMEA)
