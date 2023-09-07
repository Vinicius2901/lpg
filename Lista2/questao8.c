#include <stdio.h>

int soma_it(int n);
int soma_rec(int n);

int main()
{
    int n;
    printf("Digite um numero: ");
    scanf("%i", &n);

    int soma1 = soma_it(n);
    printf("Resultado iterativo: %i\n", soma1);

    int soma2 = soma_rec(n);
    printf("Resultado recursivo: %i\n", soma2);

    return 0;
}

int soma_it(int n)
{
    int i, termo = 0;
    for (i = 1; i <= n; i++)
    {
        termo += i;
    }
    return termo;
}

int soma_rec(int n)
{
    if (n > 0)
    {
        return n + soma_rec(n-1);
    }
}