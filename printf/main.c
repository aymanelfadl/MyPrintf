#include <stdio.h>
#include "ft_printf.h" 
#include <limits.h>

int main(void)
{
    int i = printf("k%k%%k%%k%");
    printf("\n%d",i);
    return i;
}