#include <stdio.h>
#include "ft_printf.h" 
#include <limits.h>

int main(void)
{
    int i = ft_printf("kkc%");
    printf("\n%d",i);
    return i;
}