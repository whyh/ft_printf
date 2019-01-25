cmake_minimum_required(VERSION 3.13)
project(ft_printf)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(libft LIBFT)
AUX_SOURCE_DIRECTORY(ft_printf FT_PRINTF)

add_executable(ft_printf ${LIBFT}
        ft_printf ${FT_PRINTF}
        ft_printf/ft_printf_typedefs.h
        libft/ft_gnl_typedefs.h
        libft/libft.h
        ft_printf/ft_printf.h
        ft_printf/ft_printf.c
        main.c
        ft_printf/ft_printf_parse.c
        ft_printf/ft_printf_diouxx.c
        ft_printf/ft_printf_fill_funs.c
        ft_printf/ft_printf_cspf.c
        ft_printf/ft_printf_hash_zero_blank_plus.c
        libft/ft_strndup.c
        libft/ft_strinject.c
        ft_printf/ft_printf_prec.c
        ft_printf/ft_printf_mod0_b_cap_udo.c
        ft_printf/ft_printf_width.c
        libft/libft_typedefs.h
        ft_printf/ft_printf_lhllhhl.c
        ft_printf/ft_printf_0_base.c ft_printf/ft_printf_zj.c ft_printf/ft_printf_r.c ft_printf/ft_printf_unicode.c)

link_libraries(libft/libft.a)