#include <stdio.h>
#include "ft_printf.h" 
#include <limits.h>

int main(void)
{
    int i = printf("kkc%d%",10);
    printf("\n%d",i);
    return i;
}