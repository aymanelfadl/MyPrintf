#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int	ft_puthexa(long n);
int	ft_putHEXA(long n);
int	ft_putadress(void *val);
int	ft_putnbr(long n);
int	ft_strlen(char *s);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_printf(const char *str, ...);

#endif
