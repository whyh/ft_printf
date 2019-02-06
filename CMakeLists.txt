cmake_minimum_required(VERSION 3.13)

project(ft_printf)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(libft LIBFT)
AUX_SOURCE_DIRECTORY(ft_printf FT_PRINTF)

add_executable(
        ft_printf ${LIBFT}
        ft_printf ${FT_PRINTF}
        main.c)
