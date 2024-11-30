#include "ft_printf.h"

int ft_putadress(void *n)
{
    unsigned long num;
    char c;
    int count;

    count = 0;
    num = (unsigned long)n;
    if (num == 0)
        return 0;
    if (num >= 16)
        count += ft_putadress((void *)(num / 16));
    if (num % 16 < 10)
        c = (num % 16) + '0';
    else
        c = (num % 16) - 10 + 'a';

    count += write(1, &c, 1);
}
