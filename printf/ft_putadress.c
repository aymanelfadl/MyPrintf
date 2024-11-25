#include <unistd.h>

void ft_putadress(void *n)
{
    unsigned long num;
    char c;

    num = (unsigned long)n;
    if (num == 0)
        return;
    if (num >= 16)
        ft_putadress((void *)(num / 16));
    if (num % 16 < 10)
        c = (num % 16) + '0';
    else
        c = (num % 16) - 10 + 'a';

    write(1, &c, 1);
}

// #include <stdio.h>
// int main()
// {
//     int x = 0;
//     int *ptr = &x;

//     printf("%p", ptr);
//     ft_puthexa(ptr);   // Pass the pointer to the function
//     write(1, "\n", 1); // Print a newline
//     return 0;
// }
