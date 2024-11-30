# ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int ft_puthexa(long n);
int ft_putHEXA(long n);
int ft_putadress(void *n);
int ft_putnbr(long n);

# endif