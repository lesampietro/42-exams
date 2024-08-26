int main(void)
{
    int a;
    int b;
    int c;

    a = -2147483648;
    b = 42000;
    c = 0;
    printf("%s\n", itoa(a));
    printf("%s\n", itoa(b));
    printf("%s\n", itoa(c));
}