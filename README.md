# ft_printf
### My implementation of printf function in C

An objective was to replicate functional of
```c
int printf(const char *format, ...);
```
using just few basic standard library functions:
```c
ssize_t  write(int fd, const void *buf, size_t count);
void     *malloc(size_t size);
void     free(void *ptr);
void     va_start(va_list ap, argN);
argT     va_arg(va_list ap, argT);
void     va_end(va_list ap);
```
## ft_printf supports
- conversions `i` `d` `o` `u` `x` `f` `c` `s` `p` `%`
- as well as `D` `F` `X` `S` `C` `O` `U`
- flags `+` `space` `-` `#`
- length modifiers `hh` `h` `l` `ll` `L` `q` `j` `z` `t`
- precision and field width. Value of which replaced with `*` will be taken from arguments list, just as in ptintf.

### Besides, I've added few useful conversions
- `r` requires (char*), outputs it with unprintable symbols
```c
ft_printf("the true symbols of %r", " new line \012, tab \011, start of text \002");
```
![](.screenshots/unprintable_symbols.png)
- `b` requires (unsigned int), outputs it in binary
```c
ft_printf("5 in binary looks like %#b, and 9999 is definitely %b", 5, 9999);
```
![](.screenshots/binary_conv.png)
### And basic text formatting
- available colors `white` `black` `red` `green` `yellow` `blue` `magenta` `cyan`
- available text transformations `bold`

Use `[color` `[colorb` `[trsf` to specify text, background color and text transformation accordingly. Color should not be followed by lowercase letters. Specify the end of formatting with `~]` .
```c
ft_printf("[blueb[white Ukra~][yellowb[whiteIne  ~][green,[red[bold %s~]", "yep");
```
![](.screenshots/color_mod.png)

### ft_printf also mimics printf undefined behavior cases, such as
```c
ft_printf("unspecified conversion %ll", 123);
```
![](.screenshots/unspec_conv.png)
```c
ft_printf("multiple specifications %+++.1.6.f", 99.5556);
```
![](.screenshots/multiple_spec.png)
```c
ft_printf("wrong specifications %+X", 775);
```
![](.screenshots/wrong_spec.png)
```c
ft_printf("wrong order of specification %hh3ll17S", L"¥ ¢ £ ¤ ¶");
```
![](.screenshots/wrong_order_spec.png)

## Benefits
My implementation is easily modifiable. To add new functionality, just include corresponding symbol to [categorizing defines](ft_printf/ft_printf_typedefs.h) and corresponding function pointer to [array of functions](ft_printf/ft_printf_fill_funs.c). Whole project is purposely build on these defines, so if you decided to add ~~or remove~~ functionality, that's the only thing you'll have to deal with. This way not just conversions, but also length modifiers and flags can be changed.

## How to use
`libftprintf.a` library is in the root of repository, download and link it with ` clang main.c libftprintf.a ` or ` clang main.c -Lpath/ -lftprintf ` where `path/` is path to libftprintf. I've also included all required CLion files, to make it easier for ones familiar with this IDE to modify and debug.`ft_printf` is compatible with MacOS(10.12 and later), Ubuntu(18.04.1 and later). May work on other OS/versions, but I don't guarantee it will.

#### notation
libft is self made library, based on the next standard library functions:
```c
void     *malloc(size_t size);
void     free(void *ptr);
```
so it does not violate assignment requirements to use it.
