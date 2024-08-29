/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
    char    *str;
    int     digits;
    int     i = 0;
    long    lnbr = 0;

    str = NULL;
    lnrb = (long)nbr;
    if(nbr <= 0)
        digits++;
    while(nbr)
    {
        digits++;
        nbr /= 10;
    }
    str = (char *)malloc(sizeof(char) * (digits + 1));
    str[digits + 1] = '\0';
    if(nbr == 0)
    {
        str[0] = '0';
        return(str);
    }
    if(lnbr < 0)
    {
        str[0] = '-';
        lnbr *= -1;
    }
    while(digits)
    {
        str[digits] = (lnbr % 10) + '0';
        lnbr /= 10;
    }
    return(str);
}