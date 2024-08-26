/*Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>*/

#include <unistd.h>

void    repeat_alpha(char *str)
{
    int i = 0;
    int x = 0;
    int repeat;
    char res[1024];

    while(str[i])
    {
        repeat = 0;
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            repeat += (str[i] - 'a') + 1;
            while(repeat--)
            {
                res[x] = str[i];
                write(1, &res[x], 1);         
                x++;
            }
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            repeat += (str[i] - 'A') + 1;
            while(repeat--)
            {
                res[x] = str[i];
                write(1, &res[x], 1);         
                x++;
            }
        }
        else
        {
            res[x] = str[i];
            write(1, &res[x], 1);         
        }
        x++;
        i++;
    }
    return ;
}

int main(int ac, char **av)
{
    if(ac == 2)
        repeat_alpha(av[1]);
    write(1, "\n", 1);
    return (0);
}