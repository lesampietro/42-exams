#include <unistd.h>

char    *ft_strchr(char *s1, char c)
{
    while(*s1)
    {
        if(*s1 == c)
            return(s1);
        s1++;
    }
    return(0);
}

void    ft_union(char *s1, char *s2)
{
    int     i = 0;
    int     j = 0;
    char    tmp[256];

    write(1, &s1[i], 1);
    tmp[j++] = s1[i];
    i++;
    while(s1[i])
    {
        if(ft_strchr(tmp, s1[i]) == 0)
        {
            write(1, &s1[i], 1);
            tmp[j++] = s1[i];
        }
        i++;
    }
    i = 0;
    while(s2[i])
    {
        if(ft_strchr(tmp, s2[i]) == 0)
        {
            write(1, &s2[i], 1);
            tmp[j++] = s2[i];
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if(ac == 3)
        ft_union(av[1], av[2]);
    write(1, "\n", 1);
    return (0);
}