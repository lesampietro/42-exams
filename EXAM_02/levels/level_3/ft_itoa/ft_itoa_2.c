/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/

//#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char	*ft_itoa(int nbr)
{
    int n = nbr;
    int digits = 0;
    char *res = NULL;

    if(nbr == INT_MIN)
        return("-2147483648\0");
    if(nbr == 0)
        return("0\0");
    if(n < 0)
    {
        n *= -1;
        digits++;
    }
    while(n > 0)
    {
        digits++;
        n /= 10;
    }
    res = (char *)malloc(sizeof(char) * (digits + 1));
    if(nbr < 0)
    {
        res[0] = '-';
        nbr *= -1;
    }
    res[digits] = '\0';
    digits--;
    while(nbr > 0)
    {
        res[digits] = (nbr % 10) + '0';
        nbr /= 10;
        digits--;
    }
    return(res);
}

/*int main(void)
{
    printf("%s\n", ft_itoa(INT_MIN));
    printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(42));
    printf("%s\n", ft_itoa(-13268));
    return (0);
}*/
