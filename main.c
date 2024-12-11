#include <stdio.h>
#include "ft_printf.h"  // Make sure this includes your ft_printf prototype
#include <limits.h>
int main(void)
{
    int ft_ret, std_ret;

    char *null_str = NULL;
    int zero = 0;
    int min_int = INT_MIN;
    int max_int = INT_MAX;
    unsigned int max_unsigned = UINT_MAX;

 
  ft_ret = ft_printf("TFabcdef%");
    printf("\n");
    std_ret = printf("abcdef%");
    printf("\n");
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);
}
