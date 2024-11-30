
#include "ft_printf.h"


int ft_printf(const char *str, ...)
{
    va_list args;
    va_start(args, str);
    int i = 0;
    
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 'd' || str[i] == 'i')
            {
                int val = va_arg(args, int);
                ft_putnbr_fd(val, 1);
            }
            if (str[i] == 'u')
            {
                unsigned int val = (unsigned int)va_arg(args, unsigned int);
                ft_putnbr_fd(val, 1);
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
                char val = va_arg(args, int);
                ft_putchar_fd(val, 1);
            }
            if (str[i] == 's')
            {
                char *val = va_arg(args, char *);
                ft_putstr_fd(val, 1);
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
            ft_putchar_fd(str[i], 1);
        i++;
    }
    va_end(args);
    return i;
}

int main()
{
    int c = 100;
    ft_printf("dyali :hello %%, %p, %d\n", &c, ft_printf("dyali :hello %%, %p, %d\n"));
    ft_printf("dyali :hello %%, %p, %d\n", &c, ft_printf("dyali :hello %%, %p, %d\n"));
    return 0;
}