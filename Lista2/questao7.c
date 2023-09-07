#include <stdio.h>

int soma_especial (int n, int k, int x);

int main()
{
    int n, k, x;
    printf("Digite 3 numeros: ");
    scanf("%i%i%i", &n, &k, &x);

    int somatorio = soma_especial(n,k,x);

    printf("Resposta: %i", somatorio);

    return 0;
}

int soma_especial (int n, int k, int x)
{
    int i, soma = 0;
    for (i = x; n != 0; i++)
    {
        if (i % k == 0)
        {
            soma += i;
            n--;
        }
    }
    return soma;
}