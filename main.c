#include <stdio.h>
#include "ft_printf.h"  // Make sure this includes your ft_printf prototype
#include <limits.h>
int main(void)
{
    int ft_ret, std_ret;
 
  ft_ret = ft_printf("TFabcdef%");
    printf("\n");
    std_ret = printf("abcdef%");
    printf("\n");
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);
}
