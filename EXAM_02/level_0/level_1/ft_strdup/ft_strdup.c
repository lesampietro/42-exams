#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int     i;
    int     len;
    char    *dup;

    i = 0;
    len = 0;
    while(src[len])
        src[len++];
    dup = (char *)malloc(sizeof(char) * (len + 1));
    if(dup != NULL)
    {
        while(src[i])
        {
            dup[i] = src[i];
            i++;        
        }
        dup[i] = '\0';
    }
    return(dup);
}