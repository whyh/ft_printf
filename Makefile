
all:
	cd libft && make && cd ..
	clang -Wall -Wextra -Werror main.c ft_printf/*.c -Llibft/ -lft -o l && ./l

norm:
	norminette libft/*.c && norminette libft/*.h ft_printf/*.c ft_printf/*.h

clean:
	cd libft && make clean

fclean:
	cd libft && make fclean

re: fclean all