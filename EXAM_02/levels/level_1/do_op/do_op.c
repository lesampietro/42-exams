#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int    do_op(char *s1, char *s2, char *s3)
{
    int one = atoi(s1);
    int two = atoi(s3);
    if(s2[0] == '+')
        return(one + two);
    if(s2[0] == '-')
        return(one - two);
    if(s2[0] == '*')
        return(one * two);
    if(s2[0] == '/')
        return(one / two);
    if(s2[0] == '%')
        return(one % two);
    else
        return(0);
}

int main(int ac, char **av)
{
    if(ac == 4)
        printf("%i\n", do_op(av[1], av[2], av[3]));
    else
        write(1, "\n", 1);
    return (0);
}