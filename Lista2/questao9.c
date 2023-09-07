#include <stdio.h>

float harm_it(int n);
float harm_rec(int n);


int main()
{
    int n;
    printf("Digite um numero: ");
    scanf("%i", &n);

    float soma1 = harm_it(n);
    printf("Resposta iterativa: %f\n", soma1);

    float soma2 = harm_rec(n);
    printf("Resposta recursiva: %f\n", soma2);

    return 0;
}

float harm_it(int n)
{
    int i;
    float termo = 0;
    for(i = 1; i <= n; i++)
    {
        termo += 1.0/i;
    }
    return termo;
}

float harm_rec(int n)
{
    if (n > 0)
    {
        return 1.0/n + harm_rec(n-1);
    }
}