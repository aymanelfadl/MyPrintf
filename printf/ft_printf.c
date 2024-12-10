#include "ft_printf.h"

int	ft_wechkine(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '%')
			if (!(strchr("csiupdxX%", str[i])))
				return (1);
		i++;
	}
	return (0);
}

int	ft_printer(const char *c, va_list args, const char *str, int *i)
{
	if (*c == 'd' || *c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (*c == 'x')
		return (ft_puthexa(va_arg(args, int)));
	else if (*c == 'X')
		return (ft_putHEXA(va_arg(args, int)));
	else if (*c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*c == 'p')
		return (ft_putadress(va_arg(args, char *)));
	else if (*c == '%')
		return (write(1, "%", 1));
	else if (*c == '\0' && !ft_wechkine(str))
		return (-1);
	else if (*c == '\0' && ft_wechkine(str))
		return (write(1, c - 1, 1));
	return (write(1, c - 1, 1) + write(1, c, 1));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		ret;

	va_start(args, str);
	i = 0;
	count = 0;
	ret = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ret = ft_printer(str + i, args, str, &i);
			if (ret == -1)
				return (-1);
			count += ret;
			if (!str[i])
				break ;
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
