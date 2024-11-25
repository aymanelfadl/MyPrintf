#include <unistd.h>

void ft_puthexa(long n)
{
    unsigned int num;
    char c;

    num = (unsigned int)n;
    if (num == 0)
        return;
    if (num >= 16)
        ft_puthexa(num / 16);
    if (num % 16 < 10)
        c = (num % 16) + '0';
    else
        c = (num % 16) - 10 + 'a';

    write(1, &c, 1);
}
