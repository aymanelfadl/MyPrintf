#include "ft_printf.h"

int ft_putnbr(long n)
{
	int count;
	int isnega;

	isnega = 0;
	count = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return write(1, "-2147483648", ft_strlen("-2147483648"));
		write(1, "-", 1);
		n = -n;
		isnega = 1;
	}
	if (n / 10)
		count += ft_putnbr(n / 10);
	char c = n % 10 + '0';
	count += write(1, &c, 1);
	return count + isnega;
}
