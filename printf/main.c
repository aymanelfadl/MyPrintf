#include <stdio.h>
#include "ft_printf.h"  // Make sure this includes your ft_printf prototype
#include <limits.h>
int main(void)
{
    int ft_ret, std_ret;

    // Edge cases variables
    char *null_str = NULL;
    int zero = 0;
    int min_int = INT_MIN;
    int max_int = INT_MAX;
    unsigned int max_unsigned = UINT_MAX;

 
    // Basic test with all conversions
    ft_ret = ft_printf("%c %s %p %d %i %u %x %X %%\n", 'A', "Hello", (void *)0x12345, 42, 42, 12345, 0xabc, 0xABC);
    std_ret = printf("%c %s %p %d %i %u %x %X %%\n", 'A', "Hello", (void *)0x12345, 42, 42, 12345, 0xabc, 0xABC);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test %s with NULL
    ft_ret = ft_printf("%s\n", null_str);
    std_ret = printf("%s\n", null_str);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test %p with NULL pointer
    ft_ret = ft_printf("%p\n", (void *)NULL);
    std_ret = printf("%p\n", (void *)NULL);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test %d and %i with 0
    ft_ret = ft_printf("%d %i\n", zero, zero);
    std_ret = printf("%d %i\n", zero, zero);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test %u with 0
    ft_ret = ft_printf("%u\n", (unsigned int)zero);
    std_ret = printf("%u\n", (unsigned int)zero);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test %d and %i with INT_MIN and INT_MAX
    ft_ret = ft_printf("%d %d\n", min_int, max_int);
    std_ret = printf("%d %d\n", min_int, max_int);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test %u with UINT_MAX
    ft_ret = ft_printf("%u\n", max_unsigned);
    std_ret = printf("%u\n", max_unsigned);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test %x and %X with max values and zero
    ft_ret = ft_printf("%x %X %x %X\n", zero, zero, max_unsigned, max_unsigned);
    std_ret = printf("%x %X %x %X\n", zero, zero, max_unsigned, max_unsigned);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test % solo and at the end 
    ft_ret = ft_printf("abcdef%");
    printf("\n");
    std_ret = printf("abcdef%");
    printf("\n");
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    ft_ret = ft_printf(" %%%% ");
    printf("\n");
    std_ret = printf(" %%%% ");

    printf("\n");
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);



    // Test 1: Basic cases with all specifiers
    ft_ret = ft_printf("%c %s %p %d %i %u %x %X %%\n", 'A', "Hello", (void *)0x12345, 42, 42, 12345, 0xabc, 0xABC);
    std_ret = printf("%c %s %p %d %i %u %x %X %%\n", 'A', "Hello", (void *)0x12345, 42, 42, 12345, 0xabc, 0xABC);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test 2: NULL strings and pointers
    ft_ret = ft_printf("NULL string: %s | NULL pointer: %p\n", NULL, NULL);
    std_ret = printf("NULL string: %s | NULL pointer: %p\n", NULL, NULL);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test 3: Zero values for all number types
    ft_ret = ft_printf("Zero int: %d, Zero unsigned: %u, Zero hex: %x %X\n", 0, 0U, 0, 0);
    std_ret = printf("Zero int: %d, Zero unsigned: %u, Zero hex: %x %X\n", 0, 0U, 0, 0);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test 4: Maximum and minimum integer values
    ft_ret = ft_printf("INT_MIN: %d, INT_MAX: %d, UINT_MAX: %u\n", INT_MIN, INT_MAX, UINT_MAX);
    std_ret = printf("INT_MIN: %d, INT_MAX: %d, UINT_MAX: %u\n", INT_MIN, INT_MAX, UINT_MAX);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test 5: Large hexadecimal values
    ft_ret = ft_printf("Hex max: %x %X\n", UINT_MAX, UINT_MAX);
    std_ret = printf("Hex max: %x %X\n", UINT_MAX, UINT_MAX);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test 6: Special characters in strings
    ft_ret = ft_printf("Newline: %s | Tab: %s | Percent: %%\n", "Hello\nWorld", "Hello\tWorld");
    std_ret = printf("Newline: %s | Tab: %s | Percent: %%\n", "Hello\nWorld", "Hello\tWorld");
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test 7: Edge cases with mixed formatting
    ft_ret = ft_printf("Mix: %c %s %p %d %u %x %X %%\n", 'B', "", (void *)0, -42, UINT_MAX, INT_MIN, INT_MAX);
    std_ret = printf("Mix: %c %s %p %d %u %x %X %%\n", 'B', "", (void *)0, -42, UINT_MAX, INT_MIN, INT_MAX);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test 8: Printing very long strings
    char long_str[1001];
    for (int i = 0; i < 1000; i++) long_str[i] = 'A';
    long_str[1000] = '\0';
    ft_ret = ft_printf("Long string: %s\n", long_str);
    std_ret = printf("Long string: %s\n", long_str);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test 9: Consecutive format specifiers without spaces
    ft_ret = ft_printf("Consecutive: %c%s%d%u%x%X\n", 'C', "Test", 123, 456U, 0xabc, 0xABC);
    std_ret = printf("Consecutive: %c%s%d%u%x%X\n", 'C', "Test", 123, 456U, 0xabc, 0xABC);
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    // Test 10: Edge cases with single character strings
    ft_ret = ft_printf("Single char string: %s\n", "A");
    std_ret = printf("Single char string: %s\n", "A");
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    
 // Test 10: Edge cases with single character strings
    ft_ret = ft_printf("%%%k\n");
    std_ret = printf("%%%k\n");
    printf("Return: ft_printf = %d, std_printf = %d\n\n", ft_ret, std_ret);

    return 0;
}