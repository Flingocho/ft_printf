#include "../include/ft_printf.h"

int main(void)
{
    char *str = "world";
    int num = 42;
    
    // Basic test
    ft_printf("-------- ft_printf Testing --------\n\n");
    
    // Testing all format specifiers
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", str);
    ft_printf("Pointer: %p\n", &num);
    ft_printf("Decimal (base 10): %d\n", num);
    ft_printf("Integer in base 10: %i\n", num);
    ft_printf("Unsigned decimal: %u\n", 4294967295U);
    ft_printf("Hexadecimal (lowercase): %x\n", num);
    ft_printf("Hexadecimal (uppercase): %X\n", num);
    ft_printf("Percentage sign: %%\n");
    
    // Multiple format specifiers in one string
    ft_printf("\nMultiple formats: %s is %d and in hex is %x\n", str, num, num);
    
    // Return value check
    int count = ft_printf("Return value test: %d\n", 123);
    ft_printf("The previous line printed %d characters\n", count);
    
    ft_printf("\n-------- End of Testing --------\n");
    
    return (0);
}
