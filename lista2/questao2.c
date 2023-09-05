#include <stdio.h>

int maior(int a, int b, int c);

int main()
{
    int x, y, z;

    printf("Digite tres valores: ");
    scanf("%i%i%i", &x, &y, &z);

    int resposta = maior(x, y, z);
    printf("O maior numero eh: %i\n", resposta);

    return 0;
}

int maior(int a, int b, int c)
{
    if (a >= b && a >= c)
    {
        return a;
    }
    if ((b > a && b > c) || (a == b && b > c) || (b == c && b > a))
    {
        return b;
    }
    if (c > a && c > b)
    {
        return c;
    }
}