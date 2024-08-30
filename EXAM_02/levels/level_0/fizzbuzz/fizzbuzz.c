#include <unistd.h>
#include <stdio.h>

void    putnbr(int nbr)
{
    char    c;
    if(nbr >= 10)
        putnbr(nbr / 10);
    c = nbr % 10 + '0';
    write(1, &c, 1);
}

int main(void)
{
    int max = 100;
    int nbr = 1;

    while(nbr <= max)
    {
        if(nbr % 3 != 0 && nbr % 5 != 0)
        {
            putnbr(nbr);
            write(1, "\n", 1);
        }
        if(nbr % 3 == 0 && nbr % 5 != 0)
            write(1, "fizz\n", 5);
        if(nbr % 5 == 0 && nbr % 3 != 0)
            write(1, "buzz\n", 5);
        if(nbr % 3 == 0 && nbr % 5 == 0)
            write(1, "fizzbuzz\n", 9);
        nbr++;
    }
    return(0);
}