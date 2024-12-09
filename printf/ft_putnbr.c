#include "ft_printf.h"

int ft_putnbr(long n)
{
	int count;
	int isnega;

	isnega = 0;
	count = 0;
	if (n < 0)
	{
		n = -n;
		isnega = 1;
		write(1,"-",1);
	}
	if (n / 10)
		count += ft_putnbr(n / 10);
	char c = n % 10 + '0';
	count += write(1, &c, 1);
	return count + isnega;
}
