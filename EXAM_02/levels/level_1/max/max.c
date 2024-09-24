/*Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.*/

//#include <stdio.h>

int max(int* tab, unsigned int len)
{
    unsigned int i = 0;
    int max = tab[i];

    while(i < (len - 1))
    {
        i++;
        if(max < tab[i])
            max = tab[i];
    }
    return(max);
}

/*int main(void)
{
    int tab[5] = {1, 4, 54392, 24, 566};
    printf("%i", max(tab, 5));
    return (0);
}*/