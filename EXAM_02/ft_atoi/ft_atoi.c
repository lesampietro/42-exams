#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int ft_atoi(char *str)
{
    int nbr;
    int sign;

    nbr = 0;
    sign = 1;
    if(isspace(*str))
        str++;
    if(*str == '-')
    {
        str++;
        sign = -1;
    }
    while(*str >= 48 && *str <= 57)
    {
        nbr *= 10;
        nbr += *str - 48;
        str++;    
    }
    nbr *= sign;
    return (nbr);
}

int main(void)
{
    char    *str = {"14356"};
    char    *str_01 = {"-2147483648"};
    
    printf("Resultado 01 = %d\n", ft_atoi(str));
    printf("Resultado 02 = %d\n", ft_atoi(str_01));

    return(0);
}