//#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int putstr(char *str)
{
    int count = 0;

    if(!str)
        return (write(1, "(null)", 6));
    while(*str)
    {
        write(1, str, 1);
        ++count;
        ++str;
    }
    return (count);
}

int putnum(long num, int base)
{
    int count = 0;
    char    *b = "0123456789abcdef";
    
    if (num < 0)
    {
        write(1, "-", 1);
        return (putnum(num*-1, base) + 1); //plus one for the minus sign
    }
    else if (num < base)
        return (write(1, &b[num], 1));
    else
    {
        count = putnum(num / base, base);
        return (count + putnum(num % base, base));
    }
}

int print_format(char specifier, va_list args)
{
    int count = 0;

    if (specifier == 's')
        count += putstr(va_arg(args, char *));
    else if (specifier == 'd')
        count += putnum((long)va_arg(args, int), 10);
    else if (specifier == 'x')
        count += putnum((long)va_arg(args, unsigned int), 16);
    else
        count += write(1, &specifier, 1);
    return (count);
}

int ft_printf(const char *format, ... )
{
    va_list args;
    int     count = 0;
    
    va_start(args, format); // makes args point to the first argument
    while (*format)
    {
        if (*format == '%')
            count += print_format(*(++format), args);
        else
            count += write(1, format, 1);
        ++format;
    }
    va_end(args);
    return (count);
}

/*int main(void)
{
    char    *str = NULL;
    int     decimal = -1789;
    int     bytes = 0;

    bytes = ft_printf("MY STR %s\n", str);
    printf("Bytes MY STR = %i\n", bytes);
    bytes = printf("ORIGIN %s\n", str);
    printf("Bytes ORIGINAL STR = %i\n", bytes);

    bytes = ft_printf("MY DEC %d\n", decimal);
    printf("Bytes MY DECIMAL = %i\n", bytes);
    bytes = printf("ORIGIN %d\n", decimal);
    printf("Bytes ORIGINAL DECIMAL = %i\n", bytes);
    
    bytes = ft_printf("MY HEX %x\n", decimal);
    printf("Bytes MY HEX = %i\n", bytes);
    bytes = printf("ORIGIN %x\n", decimal);
    printf("Bytes MY HEX = %i\n", bytes);

    bytes = ft_printf("MY MIX %s AND %d\n", str, decimal);
    printf("Bytes MY MIX = %i\n", bytes);
    bytes = printf("ORIGIN %s AND %d\n", str, decimal);
    printf("Bytes MIXED = %i\n", bytes);
    
    return (0);
}*/