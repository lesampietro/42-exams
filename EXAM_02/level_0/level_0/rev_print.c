#include <unistd.h>

void    rev_print(char *str)
{
    int     i;

    i = 0;
    while(str[i] != '\0')
        i++;
    while(i > 0) // because of the previous loop we might have one extra index to count, that will put "trash" at the end of the displayed word.
        write(1, &str[--i], 1); //needs to decrement before "entering" the function write, so it will not print trash at the front of the displayed word.
}

int main(int ac, char **av)
{
    if(ac == 2)
        rev_print(av[1]);
    write(1, "\n", 1);
    
    return(0);
}
