#include "ft_printf.h"

int ft_putHEXA(long n)
{
    unsigned int num;
    char c;
    int count;

    num = (unsigned int)n;
    count = 0;
    if (num == 0)
        return 0;
    if (num >= 16)
        count += ft_putHEXA(num / 16);
    if (num % 16 < 10)
        c = (num % 16) + '0';
    else
        c = (num % 16) - 10 + 'A';
    count += write(1, &c, 1);
    return count;
}
