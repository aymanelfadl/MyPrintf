#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list args;
    va_start(args, str);
    int i = 0;
    int count = 0;
    
    if (!str)
        return (0);
    while (str[i] != '\0')
    {
        if (str[i] == '%' && str[i+1] != '\0')
        {
            i++;
            if (str[i] == 'd' || str[i] == 'i')
                count += ft_putnbr(va_arg(args, int));
            else if (str[i] == 'u')
                count += ft_putnbr(va_arg(args, unsigned int));
            else if (str[i] == 'x')
                count += ft_puthexa(va_arg(args, int));
            else if (str[i] == 'X')
                count += ft_putHEXA(va_arg(args, int));
            else if (str[i] == 'c')
                count += ft_putchar(va_arg(args, int));
            else if (str[i] == 's')
                count += ft_putstr(va_arg(args, char *));
            else if (str[i] == 'p')
            {
                void *val =  va_arg(args, char *);
                if (!val)
                    count += ft_putadress(val);
                else
                {
                    count += write(1, "0x", ft_strlen("0x"));
                    count += ft_putadress(val);
                }
            }
            else if (str[i] == '%')
                count += write(1, "%%", 1);
            else
            {
                count += write(1, &str[i-1],1);
                count += write(1, &str[i], 1);
            }
        }
        else
            count += write(1,&str[i],1);
        i++;
    }
    va_end(args);
    return count;
}
