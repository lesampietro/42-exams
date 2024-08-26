#include <unistd.h>
#include <stdlib.h>

int count_chars(char *str)
{
    int i;
    int underscore;

    i = 0;
    underscore = 0;
    while(*str)
    {
        if(*str == '_')
            underscore++;
        i++;
        str++;
    }
    i -= underscore;
    return(i);
}

void    snake_to_camel(char *str)
{
    int     size;
    char    *camel;
    int     i;
    int     j;

    i = 0;
    j = 0;
    size = count_chars(str);
    camel = (char *)malloc(sizeof(char) * size);
    while(str[i])
    {
        if(str[i] == '_')
        {
            i++;
            str[i] -= 32;
        }
        camel[j] = str[i];
        write(1, &camel[j], 1);
        j++;
        i++;
    }
    free(camel);
}

int main(int ac, char **av)
{
    if(ac == 2)
        snake_to_camel(av[1]);
    write(1, "\n", 1);
    return(0);
}