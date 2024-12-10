#include <stdio.h>
#include "ft_printf.h" 
#include <limits.h>

int main(void)
{
    int i = printf("%%kk%");
    printf("\n%d\n",i);
    int j = ft_printf("%%kk%");
    ft_printf("\n%d",j);
    return i;
}