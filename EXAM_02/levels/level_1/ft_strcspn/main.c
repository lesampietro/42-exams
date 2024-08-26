#include <string.h> //for original strcspn
#include <stdio.h>

int main(void)
{
    char *s1;
    char *s2;
    int size = 0;

    s1 = "Hello, world!";
    s2 = "21791";
    size = ft_strcspn(s1, s2);
    printf("size: %i\n", size);
    printf("size: %li\n", strcspn(s1, s2));
}