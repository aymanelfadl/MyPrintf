
#include "ft_printf.h"

// @todo add return value and fix ur code ya lma3gaze
int ft_printf(const char *str, ...)
{
    va_list args;
    va_start(args, str);
    int i = 0;

    if (!str)
        return (0);

    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 'd' || str[i] == 'i')
            {
                int val = va_arg(args, int);
                ft_putnbr(val);
            }
            if (str[i] == 'u')
            {
                unsigned int val = (unsigned int)va_arg(args, unsigned int);
                ft_putnbr(val);
            }
            if (str[i] == 'x')
            {
                int val = va_arg(args, int);
                ft_puthexa(val);
            }
            if (str[i] == 'X')
            {
                int val = va_arg(args, int);
                ft_putHEXA(val);
            }
            if (str[i] == 'c')
            {
                // @todo
                char val = va_arg(args, int);
                ft_putchar(val);
            }
            if (str[i] == 's')
            {
                char *val = va_arg(args, char *);
                ft_putstr(val);
            }
            if (str[i] == 'p')
            {
                void *val = va_arg(args, char *);
                write(1, "0x", 2);
                ft_putadress(val);
            }
            if (str[i] == '%')
            {
                write(1, "%%", 1);
            }
        }
        else
            ft_putchar(str[i]);
        i++;
    }
    va_end(args);
    return i;
}
