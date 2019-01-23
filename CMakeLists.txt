cmake_minimum_required(VERSION 3.13)
project(ft_printf)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(libft LIBFT)
AUX_SOURCE_DIRECTORY(ft_printf FT_PRINTF)

add_executable(ft_printf ${LIBFT}
        ft_printf ${FT_PRINTF}
        libft/libft.h
        ft_printf/ft_printf.h
        ft_printf/ft_printf.c
        main.c
        ft_printf/ft_printf_parse.c
        ft_printf/ft_printf_convs_diouxx.c ft_printf/ft_printf_fill_funs.c ft_printf/ft_printf_convs_cspf.c ft_printf/ft_printf_flags_base.c libft/ft_strndup.c libft/ft_strinject.c ft_printf/ft_printf_prec.c main.c main.c ft_printf/ft_printf_conv_mod0.c ft_printf/ft_printf_width.c)

link_libraries(libft/libft.a)