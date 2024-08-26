/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/

#include <stdlib.h>
#include <stdio.h>

/*int count_digits(long nbr)
{
    int digits;

    digits = 0;
    if(l_nbr < 0)
    {
        l_nbr *= -1;
        digits++;
    }
    while(l_nbr > 0)
    {
        l_nbr /= 10;
        digits++;
    }
    return(digits);
}*/

char    *itoa(int nbr)
{
    char    *alpha;
    int     size;
    int     n;

    n = nbr;
    size = 0;
    //size = count_digits(nbr);
    if(nbr == -2147483648) //dealing with INT_MIN at the beginning so there is no need to creat a long variable (but it would work as well doing so)
        return("-2147483648\0");
    if(nbr <= 0)
        size++;
    while(n)
    {
        n /= 10; //to count the digits, increment "size" for each iteration. Each time n is divided by ten, is like "taking off" the last digit of that number into account. 
        size++;
    }
    printf("size: %i\n", size);
    alpha = (char *)malloc(sizeof(char) * (size + 1));
    if(!alpha)
        return (NULL);
    alpha[size] = '\0'; //put null on the last slot of the array, before entering the conditional loops
    if(nbr == 0)
    {
        alpha[0] = '0';
        return(alpha);
    }
    if(nbr < 0)
    {
        alpha[0] = '-';
        nbr *= -1;
    }
    while(nbr)
    {
        alpha[--size] = (nbr % 10) + '0'; //using our size as index so it is possible to decrement and write the digits in reverse onto the array. 
        nbr /= 10; //again, dividing by ten in order to "lose" the last digit of the number
    }
    return(alpha);
}

//MOD 10 AND REMAINDER OPERATIONS
//Mod 10 will give the remainder when a number will be devided by 10. 
//It will be always between 0 to 9 inclusive. Mod can also be calculated for negative numbers.
//In mathematics, the remainder is the amount "left over" after performing some computation. 
//In arithmetic, the remainder is the integer "left over" after dividing one integer by another to produce an integer quotient.