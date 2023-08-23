#include <stdio.h>

int main()
{
    int n, i, x, neutros = 0, positivos = 0, negativos = 0, pares = 0, impares = 0;
    printf("Digite o numero de termos: ");
    scanf("%i", &n);
    
    printf("Digite numeros inteiros: ");

    for (i = 0; i < n; i++)
    {
        scanf("%i", &x);
        if(x == 0)
        {
            neutros++;
        }
        else if (x > 0)
        {
            positivos++;
        }
        else
        {
            negativos++;
        }
        if(x % 2 == 0)
        {
            pares++;
        }
        else
        {
            impares++;
        }
    }
    printf("%i valor(es) pares\n", pares);
    printf("%i valor(es) impares\n", impares);
    printf("%i valor(es) positivos\n", positivos);
    printf("%i valor(es) negativos\n", negativos);
    printf("%i valor(es) neutros\n", neutros);
    
    return 0;
}