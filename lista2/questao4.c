#include <stdio.h>

int impares (int x, int y);

int main()
{
    int x, y, aux = 0;

    printf("Digite dois numeros: ");
    scanf("%i%i", &x, &y);

    if (x > y)
    {
        aux = y;
        y = x;
        x = aux;
    }
    int resposta = impares(x+1, y);
    printf("A soma dos numeros impares entre %i e %i eh %i",  x, y, resposta);

    return 0;
}

int impares (int x, int y)
{
    if (x % 2 == 0)
    {
        x++;
    }
    if (x >= y)
    {
        return 0;
    }
    if (x < y)
    {
        return x + impares (x + 2, y);
    }
}