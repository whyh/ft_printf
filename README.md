# ft_printf
### My implementation of printf function in C

Replicated functional of
```c
int printf(const char *format, ...);
```

Using just 6 standard C library functions
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
- more conversions `D` `F` `X` `S` `C` `O` `U`
- flags `+` `space` `-` `#`
- length modifiers `hh` `h` `l` `ll` `L` `q` `j` `z` `t`
- precision and field width. Value of which replaced with `*` will be taken from arguments list, just as in `ptintf`

### Additionally, created my own conversion
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
### Implemented text colouring
- available colors `white` `black` `red` `green` `yellow` `blue` `magenta` `cyan`
- available text transformations `bold`

Use `[color` `[colorb` `[trsf` to specify text, background color and text transformation accordingly. Color should not be followed by lowercase letters. Specify the end of formatting with `~]`
```c
ft_printf("[blueb[white Ukra~][yellowb[whiteIne  ~][green,[red[bold %s~]", "yep");
```
![](.screenshots/color_mod.png)

### ft_printf mimics printf undefined behavior cases, such as
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
My implementation is easily modifiable. To add new functionality, just include corresponding symbol to [categorizing defines](ft_printf/ft_printf_typedefs.h) and corresponding function pointer to [array of functions](ft_printf/ft_printf_fill_funs.c)

Those are the only places, that have to be modified to add new functionality (conversions, length modifiers, and flags)

## How to use
Download and run with` clang main.c libftprintf.a `


Tested for compatibility with MacOS 10.12, Ubuntu 18.04.1
