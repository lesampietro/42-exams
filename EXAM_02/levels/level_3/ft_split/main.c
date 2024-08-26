#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int j;
    char   **res;

    if(ac < 2)
        return (1);
    res = ft_split(av[1]);
    while(res[i])
    {
        j = 0;
        while(res[i][j])
        {
            write(1, &res[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
    return (0);
}