#include <unistd.h>
#include <stdio.h>

void    putnbr(int nbr)
 {
    char        str[10];
    long        lnbr;
    int         i;

    i = -1;
    lnbr = nbr;
    if(nbr == 0)
    {
        write(1, "0", 1);
        return ;
    }
    if (nbr < 0)
    {
        lnbr *= -1;
        write(1, "-", 1);
    }
    while(lnbr % 10)
    {
        str[i++] = (lnbr % 10) + '0';
        lnbr /= 10;
    }
    while(i >= 0)
        write(1, &str[--i], 1);
 }

int main(void)
{
    int nbr = -2147483648;
    int nbr01 = -42;
    int nbr02 = 42;
    int nbr03 = 0;

    putnbr(nbr);
    write(1, "\n", 1);
    putnbr(nbr01);
    write(1, "\n", 1);
    putnbr(nbr02);
    write(1, "\n", 1);
    putnbr(nbr03);
    write(1, "\n", 1);

    return(0);
}