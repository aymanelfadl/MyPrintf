#include "ft_printf.h"

int ft_printer(const char *c, va_list args)
{
    int count = 0;
    if (*c == 'd' || *c == 'i')
        count += ft_putnbr(va_arg(args, int));
    else if (*c == 'u')
        count += ft_putnbr(va_arg(args, unsigned int));
    else if (*c == 'x')
        count += ft_puthexa(va_arg(args, int));
    else if (*c == 'X')
        count += ft_putHEXA(va_arg(args, int));
    else if (*c == 'c')
        count += ft_putchar(va_arg(args, int));
    else if (*c == 's')
        count += ft_putstr(va_arg(args, char *));
    else if (*c == 'p')
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
    else if (*c == '%')
        count += write(1, "%", 1);
    else 
    {
        count += write(1, c-1 ,1);
        count += write(1, c, 1);
    }
    return count;
}

int ft_wechkine(const char *str)
{
    int len = ft_strlen((char *)str) - 2;
    while(len> 0)
    {
        if (*(str+len) == '%')
            return 1;
        len--;
    }
    return 0;
}
int ft_printf(const char *str, ...)
{
    va_list args;
    va_start(args, str);
    int i = 0;
    int count = 0;
    int kine = ft_wechkine(str);
    printf("kine: %d\n",kine);
    
    if (!str)
        return (0);
    while (str[i] != '\0')
    {
        if (str[i] != '%')
           count += write(1,&str[i],1);
        else if (str[i] == '%' && str[i+1] != '\0')
        {
            i++;
            count += ft_printer(str+i,args);
        }
        else if (kine && str[i+1] == '\0')
           count += write(1,&str[i],1);
        else 
            return -1;
        i++;
    }
    va_end(args);

    return count;
}
